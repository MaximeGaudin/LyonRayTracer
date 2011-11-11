#include "Sphere.hpp"

  Sphere::Sphere ( Vector < double, 3 > centre, double radius )
  : Geometry ( )
  , centre_(centre)
    , radius_(radius) 
{}

  Sphere::Sphere ( Vector < double, 3 > centre, double radius, Material material )
  : Geometry(material)
  , centre_(centre)
    , radius_(radius) 
{}

HitRecord Sphere::getRecord( Ray ray ) const {
  Vector3d d = ray.direction().Normalized();
  Vector3d p0 = ray.from();
  Vector3d pc = centre_;

  double A = Vector3d::Dot ( d, d );
  double B = 2 * Vector3d::Dot ( d, p0 - pc );
  double C = Vector3d::Dot ( p0 - pc, p0 - pc ) - radius_ * radius_;

  double Delta = B * B - 4 * (A * C);

  double t = -1;
  if (Delta == 0) t = -B / (2 * A);
  if (Delta > 0)
  {
    double T1 = (-B + sqrt(Delta)) / (2 * A);
    double T2 = (-B - sqrt(Delta)) / (2 * A);

    if ( T1 < 0 ) t = T2;
    else if ( T2 < 0 ) t = T1;
    else t = min(T1, T2);
  }

  HitRecord record;
  record.hit = (t > 0);
  record.hitGeometry = this;
  if ( t > 0 ) {
    record.t = t;
    record.position = ray.from() + ray.direction() * t;
    record.normal = (record.position - centre_) * (1.0 / radius_);
  }

  return record;
}
