#include <common.hpp>

#include <Maths.hpp>
#include <Basics.hpp>
#include <Cameras.hpp>
#include <Graphics.hpp>
#include <Lights.hpp>
#include <Geometries.hpp>
#include <Samplers.hpp>

#include <iostream>
#include <limits>

#include <Scene.hpp>
#include <SceneReader.hpp>

#include <boost/foreach.hpp>

#include <PNGHandler.hpp>

using namespace std;

const unsigned char MAX_RECURSION = 8;

HitRecord getClosestHit ( Ray ray, vector<Geometry*> const& geometries ) {
  HitRecord closestHit; closestHit.hit = false;
  double closestT = numeric_limits<double>::infinity();

  feach ( Geometry* g, geometries ) {
    HitRecord record = g->getRecord ( ray );

    if ( record.hit && record.t < closestT ) {
      closestT = record.t;
      closestHit = record;
    }
  }

  return closestHit;
}

Color_d computeDirectLighting ( Scene const& scene, HitRecord record ) {
  Color_d result ( Color_d_BLACK );

  feach ( Light* l, scene.lights )
    result += l->getContribution ( scene.camera, scene.geometries, record );

  return result.Clamped();
}

void displayProgress ( unsigned int Y, unsigned int H ) {
  double percentage = ((double)Y / (double)H) * 100.0;
  if ( fmod( percentage, 10.0 ) == 0.0 ) cout << endl << percentage << "%";
  else { cout << "."; cout.flush(); }
}

Ray getReflectedRay ( Ray const& ray, HitRecord const& record ) {
  double d = Vector3d::Dot ( record.normal, -ray.direction() );
  return Ray ( record.position + 0.01 * record.normal, ( 2 * record.normal * d ) + ray.direction() );
}


Ray getRefractedRay ( Ray const& ray, double IOR, HitRecord const& record ) {
  double n1 = IOR;
  double n2 = record.hitGeometry->material()->IOR;
  double n = n1 / n2;

  //cout << n << endl;
  double d = Vector3d::Dot ( record.normal, -ray.direction() );
  double c = sqrt( 1 - n * n * (1 - d * d) );

  bool input = ( abs ( Vector3d::Dot ( ray.direction(), record.normal ) ) > M_PI / 2.0 );
  Vector3d bias = ( input ) ? -0.01 * record.normal : 0.01 * record.normal;
  Ray newRay ( record.position + bias, ( n * ray.direction() ) + ( n * d - c ) * record.normal );

  //cout << "Original : " << ray.direction() << endl;
  //cout << "New : " << newRay.direction() << endl;

  return newRay;
}

Color_d getPixel ( Scene const& scene, Ray const& ray, 
    double IOR,
    unsigned char recursionsLevel ) {

  Color_d c;
  if ( recursionsLevel > MAX_RECURSION ) return c;

  HitRecord record = getClosestHit ( ray, scene.geometries );

  if ( record.hit ) {
    Color_d directColor = record.hitGeometry->material()->diffuse;
    Color_d directLighting = computeDirectLighting ( scene, record );

    Color_d reflectedColor;
    if ( record.hitGeometry->material()->reflexivity != 0 ) 
      reflectedColor = getPixel ( scene, 
          getReflectedRay ( ray, record ), IOR, recursionsLevel + 1 );

    Color_d refractedColor;
    if ( record.hitGeometry->material()->opacity != 1.0 ) 
      refractedColor = getPixel ( scene, 
          getRefractedRay ( ray, IOR, record ), 
          record.hitGeometry->material()->IOR, recursionsLevel + 1 );

    c += directColor * record.hitGeometry->material()->opacity;
    c += reflectedColor * record.hitGeometry->material()->reflexivity;
//    c += refractedColor * ( 1.0 - record.hitGeometry->material().opacity);
    c = c * directLighting;
  }

  c += scene.ambient;
  return c.Clamped();
}

void Render ( Scene& scene, Sampler* sampler ) {
  for ( unsigned int Y = 0; Y < scene.frame->H(); ++Y ) {
    displayProgress ( Y, scene.frame->H() );

    for ( unsigned int X = 0; X < scene.frame->W(); ++X ){
        vector<Ray> rays = sampler->getRays ( scene, X, Y );
        vector<Ray>::const_iterator it = rays.begin();

        //cout << *it << endl;
        Color_d pixel = Color_d_BLACK;

        while ( it != rays.end() ) { 
          pixel += getPixel ( scene, *it, 1.0, 0 ) / rays.size();
          ++it;
        }

        (*scene.frame)[X][Y] = pixel;
    }
  } 

  cout << endl << endl;
}

int main ( int argc, char** argv ) {
  if ( argc < 2 ) return 0;

  ImageFactory::addHandler ( new PNGHandler() );

  std::string inputFile = string(argv[1]);
  std::string outputFile = "result.png";

  if ( argc == 3 ) inputFile = string(argv[2]);

  logInformation("Core", "Builders discovering...");
  SceneReader SR;
  SR.addBuilder ( new MaterialBuilder() );

  SR.addBuilder ( new PerspectiveBuilder() );

  SR.addBuilder ( new PointBuilder() );

  SR.addBuilder ( new SphereBuilder() );
  SR.addBuilder ( new PlaneBuilder() );
  SR.addBuilder ( new MeshBuilder() );

  logInformation("Core", "Building scene...");
  Scene scene = SR.read ( inputFile );

  Sampler* sampler = new DefaultSampler ();
  logInformation ( "Core", "Rendering..." );
  Render ( scene, sampler ); 

  logInformation ( "Core", "Saving..." );
  ImageFactory::Save ( *scene.frame, outputFile );

  logInformation ( "Core", "Cleanup..." );

  return 0;
}
