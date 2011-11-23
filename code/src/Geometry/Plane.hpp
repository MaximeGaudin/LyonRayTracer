#ifndef PLANE_H_
#define PLANE_H_
#include <Geometry.hpp>
#include <Vector.hpp>
#include <PlaneBuilder.hpp>

class Plane : public Geometry {
  public:
    Plane ( Vector3d const& point, Vector3d const& normal );
    Plane ( Vector3d const& point, Vector3d const& normal, Material* material );

  public:
    HitRecord getRecord ( Ray const& ray ) const;
    Vector<double, 2> getUVFromHit ( HitRecord const& record ) const;

  protected:
    Vector3d point_;
    Vector3d normal_;

  private:
    void setupUV ();
    Vector3d U_;
    Vector3d V_;
};
#endif // PLANE_H_
