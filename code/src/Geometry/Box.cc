#include "Box.hpp"

Box::Box ( Vector3d min, Vector3d max ) 
: Geometry ()
  , min_(min)
  , max_(max)
{ }

Box::Box ( Vector3d min, Vector3d max, Material material ) 
: Geometry (material)
  , min_(min)
  , max_(max)
{ }

HitRecord Box::getRecord ( Ray ray ) const {
  HitRecord record;
  record.hit = false;
  record.hitGeometry = this;

  Vector3d tMin, tMax;
  for ( unsigned int i = 0; i < 3; ++i ) {

    if ( ray.direction()[i] >= 0 ) {
     tMin[i] = (min_[i] - ray.from()[i]) / ray.direction()[i];
     tMax[i] = (max_[i] - ray.from()[i]) / ray.direction()[i];
    } else {
     tMax[i] = (min_[i] - ray.from()[i]) / ray.direction()[i];
     tMin[i] = (max_[i] - ray.from()[i]) / ray.direction()[i];
    }

    if ( i >= 1 ) {
      if ( tMin[i-i] > tMax[i] || tMin[i] > tMax[i-i] ) return record;
      if ( tMin[i] > tMin[i-i] ) tMin[i-i] = tMin[i];
      if ( tMax[i] < tMax[i-i] ) tMax[i-i] = tMax[i];
    }
  }

  record.hit = true;
}
