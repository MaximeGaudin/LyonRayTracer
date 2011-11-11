#ifndef PLANE_H_
#define PLANE_H_
#include <Geometry.hpp>

#include <Vector.hpp>

class Plane : public Geometry {
  public:
    Plane ( Vector3d point, Vector3d normal );
    Plane ( Vector3d point, Vector3d normal, Material material );

    HitRecord getRecord ( Ray ray ) const;

  protected:
    Vector3d point_;
    Vector3d normal_;
};
#endif // PLANE_H_
