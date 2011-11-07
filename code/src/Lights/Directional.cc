#include "Directional.hpp"

#include <boost/foreach.hpp>
#define feach BOOST_FOREACH

// Ctors
  Directional::Directional ( Vector3d direction ) 
  : Light ()
    , direction_(direction) 
{
  material_.diffuse = Color_d_WHITE;
}

  Directional::Directional ( Vector3d direction, Material material ) 
  : Light( material)
    , direction_(direction)
{}

// Worker methods
Color<double> Directional::getContribution ( 
    Camera* camera, 
    vector<Geometry*> geometries,
    HitRecord record ) const {

  int i = 1;
  feach (Geometry* g, geometries) {
    Ray newRay ( record.position + record.normal * 0.0001, - direction_, true );
    HitRecord currentRecord = g->getRecord ( newRay );

    if ( currentRecord.hit ) {
      return material_.ambient; // Ombre
    }
  }

  double phongCoef = Vector3d::Dot ( record.normal, -direction_ ) / (record.normal.Length() * direction_.Length());
  return material_.diffuse * phongCoef;
}
