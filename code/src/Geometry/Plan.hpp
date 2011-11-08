#ifndef PLAN_H_
#define PLAN_H_
#include <Geometry.hpp>

#include <Vector.hpp>

class Plan : public Geometry {
  public:
    Plan ( Vector3d point, Vector3d normal );
    Plan ( Vector3d point, Vector3d normal, Material material );

    HitRecord getRecord ( Ray ray ) const;

  protected:
    Vector3d point_;
    Vector3d normal_;
};
#endif // PLAN_H_
