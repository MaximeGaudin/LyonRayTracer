#ifndef TRIANGLE_H_
#define TRIANGLE_H_
#include <Geometry.hpp>

#include <Vector.hpp>

class Triangle : public Geometry {
  public:
    Triangle ( Vector3d a, Vector3d b, Vector3d c ); 
    Triangle ( Vector3d a, Vector3d b, Vector3d c, Material material ); 

    Triangle ( Vector3d a, Vector3d b, Vector3d c, Vector3d normal ); 
    Triangle ( Vector3d a, Vector3d b, Vector3d c, Vector3d normal, Material material ); 

    Triangle ( 
        Vector3d a, Vector3d b, Vector3d c, 
        Vector3d aNormal, Vector3d bNormal, Vector3d cNormal 
        );

    Triangle ( 
        Vector3d a, Vector3d b, Vector3d c, 
        Vector3d aNormal, Vector3d bNormal, Vector3d cNormal,
        Material material
        );
  public:
    HitRecord getRecord ( Ray ray ) const;

  public:
    Vector3d getBarycenter () const;
    Vector3d getA () const;
    Vector3d getB () const;
    Vector3d getC () const;

  protected:
    Vector3d a_;
    Vector3d b_;
    Vector3d c_;
    Vector3d barycentre_;

    Vector3d aNormal_;
    Vector3d bNormal_;
    Vector3d cNormal_;
};
#endif // TRIANGLE_H_
