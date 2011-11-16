#include "Box.hpp"

Box::Box () : 
  Geometry(),
  min_ (V3d_Zero),
  max_ (V3d_Zero)
{ }

Box::Box ( Vector3d const& min, Vector3d const& max ) : 
  Geometry (),
  min_(min),
  max_(max)
{ }

Box::Box ( Vector3d const& min, Vector3d const& max, Material* material ) : 
  Geometry (material),
  min_(min),
  max_(max)
{ }

HitRecord Box::getRecord ( Ray const& ray ) const {
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
  return record;
}

bool Box::contains ( const Triangle *const t ) const {
/*  Vector3d barycenter ( t->getBarycenter() );

  for( unsigned int i = 0; i < 3; ++i )
    if (!( barycenter[i] >= min_[i] && barycenter[i] <= max_[i] )) return false;

  return true;
  */

  Vector3d a = t->getA(); 
  Vector3d b = t->getB(); 
  Vector3d c = t->getC(); 

  bool isAContained = true;
  for( unsigned int i = 0; i < 3; ++i )
    if (!( a[i] >= min_[i] && a[i] <= max_[i] )) isAContained = false;

  bool isBContained = true;
  for( unsigned int i = 0; i < 3; ++i )
    if (!( b[i] >= min_[i] && b[i] <= max_[i] )) isBContained = false;

  bool isCContained = true;
  for( unsigned int i = 0; i < 3; ++i )
    if (!( c[i] >= min_[i] && c[i] <= max_[i] )) isCContained = false;

  return isAContained || isBContained || isCContained;;
}
