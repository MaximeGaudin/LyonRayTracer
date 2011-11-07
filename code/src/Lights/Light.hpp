#ifndef LIGHT_H_
#define LIGHT_H_
#include <Material.hpp>
#include <Camera.hpp>
#include <Geometry.hpp>
#include <HitRecord.hpp>

#include <vector>

using namespace std;

class Light {
  public:
    Light () {}
    Light (Material material) : material_(material) {}

  public:
    virtual Color<double> getContribution ( 
        Camera* camera, 
        vector<Geometry*> geometries,
        HitRecord record ) const = 0;

  protected:
    Material material_;
};
#endif // LIGHT_H_
