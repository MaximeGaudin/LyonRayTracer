#ifndef SPHERE_H_
#define SPHERE_H_
#include <Geometry.hpp>

class Sphere : public Geometry {
  public:
    Sphere ( Vector < double, 3 > centre, double radius );
    Sphere ( Vector < double, 3 > centre, double radius, Material material );

    HitRecord getRecord ( Ray ray ) const;

  protected:
    Vector < double, 3 > centre_;
    double radius_;
};
#endif // SPHERE_H_
