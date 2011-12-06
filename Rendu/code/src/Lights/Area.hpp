#ifndef AREA_H_
#define AREA_H_
#include <Light.hpp>
#include <common.hpp>

#include <AreaBuilder.hpp>
#include <Vector.hpp>

class Material;

class Area : public Light {
  public:
    Area ( Vector3d const& point, Vector3d const& normal, double sizeX, double sizeY, unsigned int sampling );
    Area ( Vector3d const& point, Vector3d const& normal, double sizeX, double sizeY, unsigned int sampling, Material* material );

  public:
    Color_d getContribution ( 
        Camera* camera, 
        std::vector<Geometry*> const& geometries,
        HitRecord const& record ) const;

  protected:
    Vector3d point_;
    Vector3d normal_;
    double sizeX_;
    double sizeY_;
    unsigned int sampling_;

  private:
    Vector3d IPXAxis_;
    Vector3d IPYAxis_;
    Vector3d IPZAxis_;

    void setupLightBase ( );

};
#endif // AREA_H_
