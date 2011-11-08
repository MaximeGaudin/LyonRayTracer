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

HitRecord getClosestHit ( Ray ray, vector<Geometry*> const& geometries ) {
  HitRecord closestHit; closestHit.hit = false;
  double closestT = numeric_limits<double>::infinity();

  for ( unsigned int i = 0; i < geometries.size(); ++i ) {
    HitRecord currentRecord = geometries[i]->getRecord ( ray );
    if ( currentRecord.hit && currentRecord.t < closestT ) {
      closestT = currentRecord.t;
      closestHit = currentRecord;
    }
  }

  return closestHit;
}

Color_d computeDirectLighting ( Scene& scene, HitRecord record ) {
  Color_d result ( Color_d_BLACK );

  feach ( Light* l, scene.lights )
    result += l->getContribution ( scene.camera, scene.geometries, record );

  return result;
}

void displayProgress ( unsigned int Y, unsigned int H ) {
    double percentage = ((double)Y / (double)H) * 100.0;
    if ( fmod( percentage, 10.0 ) == 0.0 ) cout << endl << percentage << "%";
    else { cout << "."; cout.flush(); }
}

void Render ( Scene& scene ) {
  vector<Ray>::const_iterator it = scene.camera->begin();

  for ( unsigned int Y = 0; Y < scene.frame->H(); ++Y ) {
    displayProgress ( Y, scene.frame->H() );
    for ( unsigned int X = 0; X < scene.frame->W(); ++X ){
      HitRecord record = getClosestHit ( *it, scene.geometries );

      if ( record.hit ) {
        Color_d directLighting = 
          computeDirectLighting ( scene, record ); 

          Color_d finalColor = record.hitGeometry->material().diffuse;
          // finalColor *= directLighting;

          (*scene.frame)[X][Y] = finalColor.Clamped();
      }

      ++it;
    }
  } 

  cout << endl;
}

Scene buildScene0 () {
  Scene scene0;

  scene0.frame = new Image ( 800, 600 );

  scene0.camera = new Perspective ( scene0.frame->W(), scene0.frame->H(),  
      (V3d_Up + V3d_Backward) * 50, V3d_Zero, V3d_Zero );

  scene0.lights.push_back ( new Directional ( V3d_Down, Material ( Color_d_WHITE ) ) );

  scene0.geometries.push_back ( new Sphere ( V3d_Zero, 20, Material ( Color_d ( 0, 0, 0.7 ) ) ) );
//  scene0.geometries.push_back ( new Plan ( V3d_Up, V3d_Down * 30, Material ( Color_d ( 0.3, 0.3, 0.3 ) ) ) );

  return scene0;
}

int main () {
  PNGWriter IW; 

  logInformation ( "Core", "Scene building..." );
  Scene scene = buildScene0();

  logInformation ( "Core", "Rendering..." );
  Render ( scene ); 

  logInformation ( "Core", "Saving..." );
  IW.Save ( *scene.frame, "result.png" );

  return 0;
}
