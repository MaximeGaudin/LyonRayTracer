#include "Triangle.hpp"
#include <Plane.hpp>

  Triangle::Triangle ( Vector3d a, Vector3d b, Vector3d c )
  : Geometry () 
  , a_(a)
  , b_(b)
    , c_(c)
{
  normal_ = Vector3d::Cross ( b - a, c - a );
}

  Triangle::Triangle ( Vector3d a, Vector3d b, Vector3d c, Vector3d normal )
  : Geometry () 
  , a_(a)
  , b_(b)
    , c_(c)
    , normal_(normal)
{ }

  Triangle::Triangle ( Vector3d a, Vector3d b, Vector3d c, Material material )
  : Geometry (material) 
  , a_(a)
  , b_(b)
    , c_(c)
{
  normal_ = Vector3d::Cross ( b - a, c - a );
}

HitRecord Triangle::getRecord ( Ray ray ) const {
  HitRecord record;
  record.hit = false;
  record.hitGeometry = this;

  HitRecord planeRecord = Plane ( a_, normal_ ).getRecord ( ray );
  if ( !planeRecord.hit ) return record;

  Vector3d u = b_ - a_;
  Vector3d v = c_ - b_;
  Vector3d w = a_ - c_;
  Vector3d x = ray.from() + planeRecord.t * ray.direction();

  if (
      Vector3d::Dot ( Vector3d::Cross ( u, x - a_ ), normal_ ) >= 0 
      && Vector3d::Dot ( Vector3d::Cross ( v, x - b_ ), normal_ ) >= 0 
      && Vector3d::Dot ( Vector3d::Cross ( w, x - c_ ), normal_ ) >= 0 )
  {
    planeRecord.hitGeometry = this;
    return planeRecord;
  }

  return record;
}
