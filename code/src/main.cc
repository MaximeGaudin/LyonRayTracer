#include <Maths.hpp>

#include <Ray.hpp>
#include <Color.hpp>

#include <Camera.hpp>
#include <Perspective.hpp>

#include <HitRecord.hpp>
#include <Geometry.hpp>
#include <Sphere.hpp>

#include <Image.hpp>
#include <JPGWriter.hpp>
#include <PNGWriter.hpp>

#include <iostream>

using namespace std;

void Render ( Image& result, Camera* camera, vector < Geometry* > geometries ) {
  vector<Ray>::const_iterator it = camera->begin();
  
  for ( unsigned int Y = 0; Y < result.H(); ++Y ) {
    for ( unsigned int X = 0; X < result.W(); ++X ){

      for ( unsigned int i = 0; i < geometries.size(); ++i )
        if(geometries[i]->getRecord ( *it ).hit ) result[X][Y] = Color<double>(1,0,0);

      ++it;
    }
  } 

}

int main () {
  Image result ( 800, 600 );

  Vector<double,3> eye; eye[2] = 40;
  Camera* camera = new Perspective ( result.W(), result.H(),  eye, Vector<double,3>(), Vector<double, 3>() );

  Geometry* sph = new Sphere ( Vector<double,3>(), 10 );
  
  vector<Geometry*> geometries;
  geometries.push_back( sph );

  Render ( result, camera, geometries );

  JPGWriter IW; 
  IW.Save ( result, "result.jpg" );
  return 0;
}
