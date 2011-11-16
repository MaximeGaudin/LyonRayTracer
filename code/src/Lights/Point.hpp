#ifndef POINT_H_
#define POINT_H_
#include <Light.hpp>
#include <common.hpp>
#include <PointBuilder.hpp>

#include <Vector.hpp>

class Point : public Light {
  public:
    Point ( Vector3d const& position );
    Point ( Vector3d const& position, Material* material );

  public:
    Color_d getContribution ( 
        Camera* camera, 
        std::vector<Geometry*> const& geometries,
        HitRecord const& record ) const;

    Vector3d getPosition() const { return position_; }

  protected:
    Vector3d position_;
};
#endif
