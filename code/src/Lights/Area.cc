#include "Area.hpp"

#include <boost/foreach.hpp>

#include <Material.hpp>
#include <Geometry.hpp>

#include <iostream>

// Ctors
Area::Area ( Vector3d const& point, Vector3d const& normal, 
    double sizeX, double sizeY, unsigned int sampling ) :
  Light (),
  normal_( normal.Normalized() ),
  point_ ( point ),
  sizeX_ ( sizeX ),
  sizeY_ ( sizeY ),
  sampling_ ( sampling )
{
  setupLightBase();
}

Area::Area ( Vector3d const& point, Vector3d const& normal, 
    double sizeX, double sizeY, unsigned int sampling,
    Material* material ) :
  Light ( material ),
  normal_( normal.Normalized() ),
  point_ ( point ),
  sizeX_ ( sizeX ),
  sizeY_ ( sizeY ),
  sampling_ ( sampling )
{
  setupLightBase();
}

void Area::setupLightBase ( ) {
  if ( normal_ != V3d_Up ) IPXAxis_ = Vector3d::Cross ( normal_, V3d_Up ).Normalized(); 
  else IPXAxis_ = Vector3d::Cross ( normal_, V3d_Left ).Normalized(); 

  IPYAxis_ = Vector3d::Cross ( normal_, IPXAxis_ ).Normalized(); 
  IPZAxis_ = Vector3d::Cross ( IPXAxis_, IPYAxis_ ).Normalized(); 

  logInformation ( "Area", 
      str( format("New area light : Point - %1%, Normal - %2%, SizeX = %3%, SizeY = %4%") 
        % point_.pretty() % normal_.pretty() % sizeX_ % sizeY_) );
}

// Worker methods
Color_d Area::getContribution ( 
    Camera* camera, 
    std::vector<Geometry*> const& geometries,
    HitRecord const& record ) const {

  Color_d finalColor = Color_d_BLACK;
  double phongCoef = Vector3d::Dot ( record.normal, -(record.position - point_).Normalized() ) 
    / (record.normal.Length() );

  if ( phongCoef == 0.0 ) return Color_d_BLACK;

  for ( double x = - sizeX_ / 2.0; x <= sizeX_ / 2.0; x += sizeX_ / sampling_ ) {
    for ( double y = - sizeY_ / 2.0; y <= sizeY_ / 2.0; y += sizeY_ / sampling_ ) {
      Vector3d from ( record.position + 0.001 * record.normal );
      Vector3d to ( point_ + x * IPXAxis_[0] + y * IPYAxis_ );

      Ray r ( from, (to - from).Normalized() );
//      std::cout << r << std::endl;

      feach (Geometry* g, geometries) {
        HitRecord currentRecord = g->getRecord ( r );

        if ( !currentRecord.hit )
          finalColor += material_->diffuse / (2 * sampling_ * sampling_);
      }
    }
  }

  return finalColor * phongCoef;
}
