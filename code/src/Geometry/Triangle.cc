#include "Triangle.hpp"

  Triangle::Triangle ( Vector3d a, Vector3d b, Vector3d c )
  : Geometry () 
  , a_(a)
  , b_(b)
    , c_(c)
{
  normal_ = Vector3d::Cross ( b - a, c - a );
}

  Triangle::Triangle ( Vector3d a, Vector3d b, Vector3d c, Material material )
  : Geometry (material) 
  , a_(a)
  , b_(b)
    , c_(c)
{
  normal_ = Vector3d::Cross ( b - a, c - a );
}

HitRecord Triangle::getRecord ( Ray ray ) const {
  Vector3d u = b_ - a_;
  Vector3d v = c_ - a_;

  double d = -1.0 * Vector3d::Dot( normal_, ray.direction() );
  Vector3d w = ray.from() - a_;

  double i = -1.0f * (Vector3d::Dot( Vector3d::Cross(w, v), ray.direction() )) / d;
  double j = -1.0f * (Vector3d::Dot( Vector3d::Cross(u, w), ray.direction() )) / d;

  HitRecord record;
  record.hit = false;
  record.hitGeometry = this;

  if (i > 0 && j > 0 && i + j <= 1) {
    record.t = (Vector3d::Dot(Vector3d::Cross(u, v), w)) / d;
    if ( record.t > 0 ) {
      record.hit = true;
      record.position = ray.from() + record.t * ray.direction();
      record.normal = normal_;
    } 
  }

  return record;
}
