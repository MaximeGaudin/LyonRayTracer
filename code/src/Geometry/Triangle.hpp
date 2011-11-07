#ifndef TRIANGLE_H_
#define TRIANGLE_H_
#include <Geometry.hpp>

#include <Vector.hpp>

class Triangle : public Geometry {
  public:
    Triangle ( Vector3d a, Vector3d b, Vector3d c ); 
    Triangle ( Vector3d a, Vector3d b, Vector3d c, Material material ); 

  public:
    HitRecord getRecord ( Ray ray ) const;

  protected:
    Vector3d a_;
    Vector3d b_;
    Vector3d c_;
    Vector3d normal_;
};
#endif // TRIANGLE_H_
