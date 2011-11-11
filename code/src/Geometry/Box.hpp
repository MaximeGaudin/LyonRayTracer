#ifndef BOX_H_
#define BOX_H_
#include <Geometry.hpp>
#include <Material.hpp>
#include <Vector.hpp>

class Box : public Geometry {
  public:
    Box ( Vector3d min, Vector3d max );
    Box ( Vector3d min, Vector3d max , Material material );

  public:
    HitRecord getRecord ( Ray ray ) const;

  protected:
    Vector3d min_;
    Vector3d max_;
};
#endif // BOX_H_
