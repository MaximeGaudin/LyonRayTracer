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

Ray getReflectedRay ( Ray const& ray, HitRecord const& record ) {
  double d = Vector3d::Dot ( record.normal, -ray.direction() );
  return Ray ( record.position + 0.01 * record.normal, ( 2 * record.normal * d ) + ray.direction(), true );
}


Ray getRefractedRay ( Ray const& ray, double IOR, HitRecord const& record ) {
  double n1 = IOR;
  double n2 = record.hitGeometry->material().IOR;
  double n = n1 / n2;

  //cout << n << endl;
  double d = Vector3d::Dot ( record.normal, -ray.direction() );
  double c = sqrt( 1 - n * n * (1 - d * d) );

  bool input = ( abs ( Vector3d::Dot ( ray.direction(), record.normal ) ) > M_PI / 2.0 );
  Vector3d bias = ( input ) ? -0.01 * record.normal : 0.01 * record.normal;
  Ray newRay ( record.position + bias, ( n * ray.direction() ) + ( n * d - c ) * record.normal, true );

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
    Color_d directColor = record.hitGeometry->material().diffuse;
    Color_d directLighting = computeDirectLighting ( scene, record );

    Color_d reflectedColor;
    if ( record.hitGeometry->material().reflexivity != 0 ) 
      reflectedColor = getPixel ( scene, 
          getReflectedRay ( ray, record ), IOR, recursionsLevel + 1 );

    Color_d refractedColor;
    if ( record.hitGeometry->material().opacity != 1.0 ) 
      refractedColor = getPixel ( scene, 
          getRefractedRay ( ray, IOR, record ), 
          record.hitGeometry->material().IOR, recursionsLevel + 1 );

    c += directColor * record.hitGeometry->material().opacity;
    c += reflectedColor * record.hitGeometry->material().reflexivity;
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

  scene.ambient = Color_d ( 0.1, 0.1, 0.1 );
  scene.frame = new Image ( 600, 600 );

  scene.camera = new Perspective ( 1.0,
      V3d_Up * 30 + V3d_Backward * 100, V3d_Zero, V3d_Zero );


  scene.lights.push_back ( new Directional ( V3d_Down, Material ( 0.5 * Color_d_WHITE ) ) );
  scene.lights.push_back ( new Directional ( V3d_Down + V3d_Forward + V3d_Right, Material ( 0.5 * Color_d_WHITE ) ) );
  //scene.lights.push_back ( new Directional ( V3d_Down, Material ( Color_d_WHITE  ) ) );

  Material semiTransparent ( Color_d ( 0.0, 0.0, 1.0 ) );
  semiTransparent.opacity = 1.0;
  semiTransparent.IOR = 1.0;
  semiTransparent.reflexivity = 0.0;
//  scene.geometries.push_back ( new Sphere ( V3d_Forward * 40, 5, Material ( Color_d ( 0,1,0)) ));

  scene.geometries.push_back ( new Sphere ( V3d_Zero, 20, semiTransparent ) );
  scene.geometries.push_back ( new Sphere ( V3d_Left * 30 + V3d_Backward * 30, 5, Material ( Color_d ( 0.9, 0, 0 ) ) ) );
  scene.geometries.push_back ( new Plane ( V3d_Down * 30, V3d_Up, Material ( Color_d( 0.0,0.9,0.0) ) ) );

  return scene;
}

Scene buildScene3 () {
  Scene scene;

  scene.frame = new Image ( 600, 600 );

  scene.camera = new Perspective ( 0.5,
     (V3d_Backward ) * 5, V3d_Zero, V3d_Zero );

  scene.lights.push_back ( new Directional ( V3d_Forward, Material ( Color_d_WHITE  ) ) );
//  scene.lights.push_back ( new Directional ( V3d_Down, Material ( Color_d_WHITE  ) ) );

  scene.geometries.push_back ( new Triangle ( V3d_Left, V3d_Up, V3d_Right, V3d_Backward, Material ( Color_d ( 1, 0, 0) ) ) );
 // scene.geometries.push_back ( new Triangle ( V3d_Backward  + V3d_Left+ V3d_Left,  V3d_Backward  + V3d_Left+ V3d_Right,  V3d_Backward  + V3d_Left+ V3d_Up, Material ( Color_d ( 0, 1, 0) ) ) );
//  scene.geometries.push_back ( new Plane ( V3d_Down * 200, V3d_Up, Material ( Color_d( 0,0,0.5) ) ) );

  return scene;
}

Scene buildScene4 () {
  Scene scene;

  scene.ambient = Color_d ( 0.1, 0.1, 0.1 );
  scene.frame = new Image ( 600, 600 );

  scene.camera = new Perspective ( 0.5,
     (V3d_Backward + V3d_Up + V3d_Right) * 4, V3d_Zero, V3d_Zero );

  scene.lights.push_back ( new Directional ( V3d_Forward + V3d_Down + V3d_Left, Material ( 0.5 * Color_d_WHITE  ) ) );
//  scene.lights.push_back ( new Directional ( V3d_Down, Material ( 0.5 * Color_d_WHITE  ) ) );

  MeshImporter3ds MI;
  scene.geometries.push_back ( MI.build ( "models/cube.3ds" ) );
//  scene.geometries.push_back ( new Plane ( V3d_Down * 5, V3d_Up, Material ( Color_d( 0.0,0.7,0.0) ) ) );

  return scene;
}

Scene buildScene5 () {
  Scene scene;

  scene.ambient = Color_d ( 0.1, 0.1, 0.1 );
  scene.frame = new Image ( 600, 600 );

  scene.camera = new Perspective ( 0.5,
     (V3d_Down + V3d_Backward + V3d_Right) * 25, V3d_Zero, V3d_Zero );

  scene.lights.push_back ( new Directional ( V3d_Up + V3d_Forward + V3d_Left, Material ( 0.5 * Color_d_WHITE  ) ) );
//  scene.lights.push_back ( new Directional ( V3d_Down, Material ( 0.5 * Color_d_WHITE  ) ) );

  MeshImporter3ds MI;
  scene.geometries.push_back ( MI.build ( "models/teapot.3ds" ) );
//  scene.geometries.push_back ( new Plane ( V3d_Down * 5, V3d_Up, Material ( Color_d( 0.0,0.7,0.0) ) ) );

  return scene;
}

Scene buildScene7 () {
  Scene scene;

  scene.ambient = Color_d ( 0.1, 0.1, 0.1 );
  scene.frame = new Image ( 600, 600 );

  scene.camera = new Perspective ( 0.5,
     (V3d_Backward + V3d_Up) * 1, V3d_Zero, V3d_Zero );

  scene.lights.push_back ( new Directional ( V3d_Forward + V3d_Down +V3d_Left, Material ( 0.5 * Color_d_WHITE  ) ) );
//  scene.lights.push_back ( new Directional ( V3d_Down, Material ( 0.5 * Color_d_WHITE  ) ) );

  MeshImporter3ds MI;
  scene.geometries.push_back ( MI.build ( "models/angel.3ds" ) );
  scene.geometries.push_back ( new Plane ( V3d_Down * 2, V3d_Up, Material ( Color_d( 0.0,0.0,0.4) ) ) );

  return scene;
}


Scene buildScene6 () {
  Scene scene;

  scene.ambient = Color_d ( 0.1, 0.1, 0.1 );
  scene.frame = new Image ( 400, 400 );

  scene.camera = new Perspective ( 0.5,
     (V3d_Backward + V3d_Up + V3d_Right) * 3, V3d_Zero, V3d_Zero );

  scene.lights.push_back ( new Directional ( V3d_Down + V3d_Forward + V3d_Left, Material ( 0.5 * Color_d_WHITE  ) ) );

  scene.geometries.push_back ( new Box ( V3d_Left + V3d_Forward + V3d_Down, V3d_Right + V3d_Backward + V3d_Up , Material ( Color_d( 0.0,0.7,0.0) ) ) );

  return scene;
}


int main () {
  PNGWriter IW; 
  Sampler* sampler = new DefaultSampler ();

  logInformation ( "Core", "Scene building..." );
  Scene scene = buildScene5();

  logInformation ( "Core", "Rendering..." );
  Render ( scene, sampler ); 

  logInformation ( "Core", "Saving..." );
  IW.Save ( *scene.frame, "result.png" );

  logInformation ( "Core", "Cleanup..." );
  delete scene.frame;

  return 0;
}
