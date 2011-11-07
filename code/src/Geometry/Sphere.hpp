#ifndef SPHERE_H_
#define SPHERE_H_
#include <Geometry.hpp>

#include <Vector.hpp>

class Sphere : public Geometry {
  public:
    /**
      * @param centre Position du centre de la sphère.
      * @param radius Rayon de la sphère.
      */
    Sphere ( Vector3d centre, double radius );

    /**
      * @param centre Position du centre de la sphère.
      * @param radius Rayon de la sphère.
      * @param material Matériaux de la sphère.
      */
    Sphere ( Vector3d centre, double radius, Material material );

    HitRecord getRecord ( Ray ray ) const;

  protected:
    Vector3d centre_;
    double radius_;
};
#endif // SPHERE_H_
