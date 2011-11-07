#include "Directional.hpp"

#include <boost/foreach.hpp>
#define feach BOOST_FOREACH

// Ctors
  Directional::Directional ( Vector<double, 3> direction ) 
  : Light ()
    , direction_(direction) 
{
  material_.diffuse = Color_d_WHITE;
}

  Directional::Directional ( Vector<double, 3> direction, Material material ) 
  : Light( material)
    , direction_(direction)
{}

// Worker methods
Color<double> Directional::getContribution ( 
    Camera* camera, 
    vector<Geometry*> geometries,
    HitRecord record ) const {

  feach (Geometry* g, geometries) {
    HitRecord currentRecord = g->getRecord ( Ray ( record.position + record.normal * 0.001, -direction_ ) );
   // cout << currentRecord << endl;

    if ( currentRecord.hit ) return Color<double>(0.0); // Ombre
  }

  double phongCoef = abs(Vector3d::Dot ( record.normal, direction_ ) );
  return material_.diffuse * phongCoef;
}
