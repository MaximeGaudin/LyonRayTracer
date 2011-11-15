#include "Geometry.hpp"

Geometry::Geometry ( Material const& material ) : 
  material_(material),
  translation_(V3d_Zero), 
  rotation_(V3d_Zero), 
  scale_(V3d_One),
  transformation_(Matrix<double,4,4>(IDENTITY))
{}

Geometry::Geometry ( 
        Material const& material, 
        Vector3d const& translation,
        Vector3d const& rotation,
        Vector3d const& scale ) :
   material_(material),
  translation_(translation), 
  rotation_(rotation), 
  scale_(scale),
  transformation_(
    Matrix<double,4,4>::Rotation ( rotation ) 
    * Matrix<double,4,4>::Scale ( scale )
    * Matrix<double,4,4>::Translation ( translation_ ))
{ }
