#ifndef DIRECTIONAL_H_
#define DIRECTIONAL_H_
#include <Light.hpp>

#include <Vector.hpp>
#include <Material.hpp>

class Directional : public Light {
  public:
    Directional ( Vector3d direction );
    Directional ( Vector3d direction, Material material );

  public:
    Color<double> getContribution ( 
        Camera* camera, 
        vector<Geometry*> geometries,
        HitRecord record ) const;

    Vector3d getDirection() { return direction_; }

  protected:
    Vector3d direction_;
};
#endif // DIRECTIONAL_H_
