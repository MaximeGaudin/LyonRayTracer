#ifndef BOX_H_
#define BOX_H_
#include <Geometry.hpp>
#include <Material.hpp>
#include <Vector.hpp>
#include <Triangle.hpp>

class Box : public Geometry {
  public:
    Box ();
    Box ( Vector3d min, Vector3d max );
    Box ( Vector3d min, Vector3d max , Material material );

  public:
    HitRecord getRecord ( Ray ray ) const;
    bool contains ( Triangle* t ) const;

  public:
    Vector3d getMin () const { return min_; }
    Vector3d getMax () const { return max_; }

  protected:
    Vector3d min_;
    Vector3d max_;
};
#endif // BOX_H_
