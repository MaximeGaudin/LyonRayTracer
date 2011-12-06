#ifndef TRIANGLE_H_
#define TRIANGLE_H_
#include <Geometry.hpp>

#include <Vector.hpp>

class Triangle : public Geometry {
  public:
    Triangle ( Vector3d const& a, Vector3d const& b, Vector3d const& c ); 
    Triangle ( 
        Vector3d const& a, Vector3d const& b, Vector3d const& c, 
        Material* material ); 

    Triangle ( 
        Vector3d const& a, Vector3d const& b, Vector3d const& c, 
        Vector3d const& normal ); 

    Triangle (
        Vector3d const& a, Vector3d const& b, Vector3d const& c, 
        Vector3d const& normal,
        Material* material ); 

    Triangle ( 
        Vector3d const& a, Vector3d const& b, Vector3d const& c, 
        Vector3d const& aNormal, Vector3d const& bNormal, Vector3d const& cNormal );

    Triangle ( 
        Vector3d const& a, Vector3d const& b, Vector3d const& c, 
        Vector3d const& aNormal, Vector3d const& bNormal, Vector3d const& cNormal,
        Material* material);

  public:
    HitRecord getRecord ( Ray const& ray ) const;

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
