#ifndef SPHERE_H_
#define SPHERE_H_
#include <Geometry.hpp>
#include <Vector.hpp>
#include <SphereBuilder.hpp>

class Sphere : public Geometry {
  public:
    /**
      * @param centre Position du centre de la sphère.
      * @param radius Rayon de la sphère.
      */
    Sphere ( Vector3d const& centre, double radius );

    /**
      * @param centre Position du centre de la sphère.
      * @param radius Rayon de la sphère.
      * @param material Matériaux de la sphère.
      */
    Sphere ( Vector3d const& centre, double radius, Material* material );

  public:
    HitRecord getRecord ( Ray const& ray ) const;

    Vector<double, 2> getUVFromHit ( HitRecord const& record ) const;

  protected:
    Vector3d centre_;
    double radius_;
};
#endif // SPHERE_H_
