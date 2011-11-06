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
  double dX = ray.direction()[0];
  double dY = ray.direction()[1];
  double dZ = ray.direction()[2];

  double fX = ray.from()[0];
  double fY = ray.from()[1];
  double fZ = ray.from()[2];

  double A = dX * dX
    + dY * dY
    + dZ * dZ;

  double B = 2 * (dX * (fX - centre_[0]))
    + 2 * (dY * (fY - centre_[1]))
    + 2 * (dZ * (fZ - centre_[2]));

  double C = (fX - centre_[0]) * (fX - centre_[0])
    + (fY - centre_[1]) * (fY - centre_[1])
    + (fZ - centre_[2]) * (fZ - centre_[2])
    - radius_ * radius_;
  double Delta = B * B - 4 * (A * C);

  double t = -1;
  if (Delta == 0) t = -B / (2 * A);
  if (Delta > 0)
  {
    double T1 = (-B + sqrt(Delta)) / (2 * A);
    double T2 = (-B - sqrt(Delta)) / (2 * A);

    t = min(T1, T2);
  }

  HitRecord record;
  record.hit = (t > 0);
  record.t = t;
  record.position = ray.from() + ray.direction() * t;
  record.normal = (record.position - centre_) * (1.0 / radius_);
  record.hitGeometry = this;

  return record;
}
