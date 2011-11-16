#include "Directional.hpp"

#include <boost/foreach.hpp>

#include <Material.hpp>
#include <Geometry.hpp>

// Ctors
Directional::Directional ( Vector3d const& direction ) :
  Light (),
  direction_(direction.Normalized()) 
{ }

Directional::Directional ( Vector3d const& direction, Material* material ) :
  Light( material),
  direction_(direction.Normalized())
{ }

// Worker methods
Color_d Directional::getContribution ( 
    Camera* camera, 
    std::vector<Geometry*> const& geometries,
    HitRecord const& record ) const {

  feach (Geometry* g, geometries) {
    Ray newRay ( record.position + record.normal * 0.0001, - direction_ );
    HitRecord currentRecord = g->getRecord ( newRay );

    if ( currentRecord.hit ) {
      return Color_d_BLACK; // Ombre
    }
  }

  double phongCoef = Vector3d::Dot ( record.normal, -direction_ ) 
    / (record.normal.Length() );
  return material_->diffuse * phongCoef;
}
