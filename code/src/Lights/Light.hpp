#ifndef LIGHT_H_
#define LIGHT_H_
#include <Buildable.hpp>
#include <common.hpp>

#include <vector>

#include <HitRecord.hpp>
#include <Color.hpp>

class Camera;
class Material;
class Geometry;

class Light : public Buildable {
  public:
    Light () {}
    Light (Material* material) : material_(material) {}

  public:
    virtual Color_d getContribution ( 
        Camera* camera, 
        std::vector<Geometry*> const& geometries,
        HitRecord const& record ) const = 0;

  protected:
    Material* material_;
};
#endif // LIGHT_H_
