#ifndef POINT_H_
#define POINT_H_
#include <common.hpp>
#include <Light.hpp>

#include <Vector.hpp>
#include <Material.hpp>

class Camera;

class Point : public Light {
  public:
    Point ( Vector3d position );
    Point ( Vector3d position, Material material );

  public:
    Color<double> getContribution ( 
        Camera* camera, 
        vector<Geometry*> geometries,
        HitRecord record ) const;

    Vector3d getPosition() { return position_; }

  protected:
    Vector3d position_;
};
#endif
