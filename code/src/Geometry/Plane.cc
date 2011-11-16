#include <Plane.hpp>

Plane::Plane ( Vector3d const& point, Vector3d const& normal ) :
  Geometry(),
  point_(point),
  normal_(normal.Normalized())
{ }

Plane::Plane ( Vector3d const& point, Vector3d const& normal, Material* material ) :
  Geometry(material),
  point_(point),
  normal_(normal.Normalized())
{ }

HitRecord Plane::getRecord ( Ray const& ray ) const {
  HitRecord record;
  record.hit = false;
  record.hitGeometry = this;

  double d = Vector3d::Dot ( ray.direction(), normal_ );

  if ( d != 0.0 ) {
    double t = -1.0 * ( Vector3d::Dot ( normal_, ray.from() ) + point_.Length() ) / d;
    if ( t >= 0 ) {
      record.hit = true;
      record.t = t;
      record.position = ray.from() + t * ray.direction();
      record.normal = normal_;
    }
  }

  return record;
}
