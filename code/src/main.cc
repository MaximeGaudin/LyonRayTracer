#include <Maths.hpp>
#include <Basics.hpp>
#include <Cameras.hpp>
#include <Graphics.hpp>
#include <Lights.hpp>
#include <Geometries.hpp>
#include <MeshImporters.hpp>

#include <iostream>
#include <limits>

#include <boost/foreach.hpp>
#define feach BOOST_FOREACH

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

Color_d getPixel ( Scene const& scene, Ray const& ray, 
    unsigned char recursionsLevel ) {
  if ( recursionsLevel > MAX_RECURSION ) return Color_d_BLACK;

  HitRecord record = getClosestHit ( ray, scene.geometries );

  if ( record.hit ) {
    Color_d directColor = record.hitGeometry->material().diffuse;
    //Color_d reflectedColor = getPixel ( scene, getReflectedRay ( ray, record.normal ), recursionsLevel + 1 );
    //Color_d refractedColor = getPixel ( scene, getRefractedRay ( ray, record.normal ), recursionsLevel + 1 );

    Color_d directLighting = computeDirectLighting ( scene, record );
   // cout << "Hit" << endl;

    // return scene.ambient + directLighting * ( directColor + reflectedColor + refractedColor );
      return scene.ambient + directLighting * ( directColor );
     //return scene.ambient + directColor;
  } else return scene.ambient;
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
          pixel += getPixel ( scene, *it, 0 ) / rays.size();
          ++it;
        }

        (*scene.frame)[X][Y] = pixel;
    }
  } 

  cout << endl << endl;
}

// Ok
Scene buildScene0 () {
  Scene scene0;

  scene0.frame = new Image ( 800, 600 );

  scene0.camera = new Perspective ( 1.0,
      V3d_Backward * 100, V3d_Zero, V3d_Zero );

  scene0.lights.push_back ( new Directional ( V3d_Down, Material ( Color_d_WHITE ) ) );

  scene0.geometries.push_back ( new Sphere ( V3d_Zero, 20, Material ( Color_d ( 0, 0, 0.7 ) ) ) );

  return scene0;
}

// Ok
Scene buildScene1 () {
  Scene scene;

  scene.frame = new Image ( 600, 600 );

  scene.camera = new Perspective ( 1.0,
      V3d_Backward * 100, V3d_Zero, V3d_Zero );

  scene.lights.push_back ( new Directional ( V3d_Forward, Material ( Color_d_WHITE ) ) );

  scene.geometries.push_back ( new Sphere ( V3d_Zero, 20, Material ( Color_d ( 0, 0, 0.7 ) ) ) );
  scene.geometries.push_back ( new Sphere ( V3d_Backward * 30, 5, Material ( Color_d ( 0.7, 0, 0 ) ) ) );

  return scene;
}

// Ok
Scene buildScene2 () {
  Scene scene;

  scene.frame = new Image ( 600, 600 );

  scene.camera = new Perspective ( 1.0,
      V3d_Backward * 100, V3d_Zero, V3d_Zero );


  scene.lights.push_back ( new Directional ( V3d_Forward + V3d_Right, Material ( Color_d_WHITE ) ) );

  scene.geometries.push_back ( new Sphere ( V3d_Zero, 20, Material ( Color_d ( 0, 0, 0.7 ) ) ) );
  scene.geometries.push_back ( new Sphere ( V3d_Left * 30 + V3d_Backward * 30, 5, Material ( Color_d ( 0.7, 0, 0 ) ) ) );

  return scene;
}

Scene buildScene3 () {
  Scene scene;

  scene.frame = new Image ( 200, 200 );

  scene.camera = new Perspective ( 0.5,
     (V3d_Backward + V3d_Up) * 25, V3d_Zero, V3d_Zero );

  scene.lights.push_back ( new Directional ( V3d_Forward, Material ( Color_d_WHITE  ) ) );
  scene.lights.push_back ( new Directional ( V3d_Down, Material ( Color_d_WHITE  ) ) );

  //scene.geometries.push_back ( new Triangle ( V3d_Left, V3d_Down, V3d_Right ) );

  MeshImporter3ds MI;
  //scene.geometries.push_back ( MI.build ( "models/cube.3ds" ) );

  scene.geometries.push_back ( new Plane ( V3d_Down * 10, V3d_Up, Material ( Color_d( 0,0,0.5) ) ) );
  scene.geometries.push_back ( MI.build ( "models/teapot.3ds" ) );

  return scene;
}

int main () {
  PNGWriter IW; 
  Sampler* sampler = new DefaultSampler ();

  logInformation ( "Core", "Scene building..." );
  Scene scene = buildScene3();

  logInformation ( "Core", "Rendering..." );
  Render ( scene, sampler ); 

  logInformation ( "Core", "Saving..." );
  IW.Save ( *scene.frame, "result.png" );

  logInformation ( "Core", "Cleanup..." );
  delete scene.frame;

  return 0;
}
