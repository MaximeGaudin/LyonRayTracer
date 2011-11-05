#ifndef MATERIAL_H_
#define MATERIAL_H_
#include <Color.hpp>

class Material {
  public:
    Material ( );

    Material ( Color<double> ambient );
    Material ( Color<double> ambient, Color<double> diffuse, Color<double> specular );

  public:
    Color<double> ambient_;
    double opacity_;
    double IOR_;
    double reflexivity_;

    Color<double> diffuse_;
    double diffuseIntensity_;

    Color<double> specular_;
    double specularPower_;
};
#endif // MATERIAL_H_
