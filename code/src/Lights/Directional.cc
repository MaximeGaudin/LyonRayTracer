#include "Directional.hpp"

#include <boost/foreach.hpp>
#define feach BOOST_FOREACH

#include <Triangle.hpp>

// Ctors
  Directional::Directional ( Vector3d direction ) 
  : Light ()
    , direction_(direction.Normalized()) 
{
  material_.diffuse = Color_d_WHITE;
}

  Directional::Directional ( Vector3d direction, Material material ) 
  : Light( material)
    , direction_(direction.Normalized())
{}

// Worker methods
Color<double> Directional::getContribution ( 
    Camera* camera, 
    vector<Geometry*> geometries,
    HitRecord record ) const {

  feach (Geometry* g, geometries) {
    Ray newRay ( record.position + record.normal * 0.0001, - direction_, true );
    HitRecord currentRecord = g->getRecord ( newRay );

    if ( currentRecord.hit ) {
      return Color_d_BLACK; // Ombre
    }
  }

  double phongCoef = Vector3d::Dot ( record.normal, -direction_ ) / (record.normal.Length() );
  return material_.diffuse * phongCoef;
}
