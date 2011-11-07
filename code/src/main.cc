#include <Maths.hpp>
#include <Basics.hpp>
#include <Cameras.hpp>
#include <Graphics.hpp>
#include <Lights.hpp>
#include <Geometries.hpp>

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

Color_d computeDirectLighting (
    HitRecord record,
    Camera* camera, 
    vector < Geometry* > const& geometries, 
    vector < Light* > const& lights ) {
  Color_d result ( Color_d_BLACK );

  feach ( Light* l, lights )
    result += l->getContribution ( camera, geometries, record );

  return result;
}

void Render ( 
    Image& result, 
    Camera* camera, 
    vector < Geometry* > const& geometries, 
    vector < Light* > const& lights ) {
  vector<Ray>::const_iterator it = camera->begin();

  for ( unsigned int Y = 0; Y < result.H(); ++Y ) {
    for ( unsigned int X = 0; X < result.W(); ++X ){
      HitRecord record = getClosestHit ( *it, geometries );
      cout << *it << endl;

      if ( record.hit ) {
        cout << "HIT!" << endl;
        Color_d directLighting = 
          computeDirectLighting ( record, camera, geometries, lights );

          Color_d finalColor = record.hitGeometry->material().diffuse;
          finalColor *= directLighting;

          result[X][Y] = finalColor.Clamped();
      }

      ++it;
    }
  } 

}

int main () {
  Image result ( 800, 600 );

  vector<Geometry*> geometries;
  vector<Light*> lights;

  Camera* camera = new Perspective ( result.W(), result.H(),  
      V3d_Backward * 40, V3d_Zero, V3d_Zero );

  geometries.push_back( new Sphere ( V3d_Zero, 10, Material ( Color_d(0.5, 0, 0 ) ) ) );
  geometries.push_back( new Sphere ( V3d_Zero, 3, Material ( Color_d(0.6) ) ) );

  lights.push_back ( new Directional (V3d_Forward, Material ( Color_d_WHITE ) ) );

  Ray r ( V3d_Backward * 40, V3d_Forward );
  cout << "Ray :" << r << endl;
  cout << "S1 :" << geometries[0]->getRecord( r ) << endl;
  cout << "S2 :" << geometries[1]->getRecord( r ) << endl;
  cout << "Closest :" << getClosestHit ( r, geometries ) << endl;
  // Render ( result, camera, geometries, lights );

  JPGWriter IW; 
  IW.Save ( result, "result.jpg" );
  return 0;
}
