#include "Point.hpp"

#include <boost/foreach.hpp>

Point::Point ( Vector3d position ) 
  : Light()
    , position_(position)
{}

Point::Point ( Vector3d position, Material material ) 
: Light(material)
  , position_(position)
{}

// Worker methods
Color<double> Point::getContribution ( 
    Camera* camera, 
    vector<Geometry*> geometries,
    HitRecord record ) const {
  Ray newRay ( record.position + record.normal * 0.0001, position_ - (record.position + record.normal * 0.0001) );

  feach (Geometry* g, geometries) {
    HitRecord currentRecord = g->getRecord ( newRay );

    if ( currentRecord.hit ) {
      return Color_d_BLACK; // Ombre
    }
  }

  double phongCoef = Vector3d::Dot ( record.normal, newRay.direction() ) / (record.normal.Length() );
  return material_.diffuse * phongCoef;
}
