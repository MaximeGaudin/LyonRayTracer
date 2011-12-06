#ifndef DIRECTIONAL_H_
#define DIRECTIONAL_H_
#include <Light.hpp>
#include <common.hpp>

#include <Vector.hpp>

class Directional : public Light {
  public:
    Directional ( Vector3d const& direction );
    Directional ( Vector3d const& direction, Material* material );

  public:
    Color_d getContribution ( 
        Camera* camera, 
        std::vector<Geometry*> const& geometries,
        HitRecord const& record ) const;

    Vector3d getDirection() const { return direction_; }

  protected:
    Vector3d direction_;
};
#endif // DIRECTIONAL_H_
