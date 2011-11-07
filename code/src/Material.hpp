#ifndef MATERIAL_H_
#define MATERIAL_H_
#include <Color.hpp>

class Material {
  public:
    Material ( );

    Material ( Color<double> diffuse );
    Material ( Color<double> diffuse, Color<double> ambient, Color<double> specular );

  public:
    Color<double> ambient;
    double opacity;
    double IOR;
    double reflexivity;

    Color<double> diffuse;
    double diffuseIntensity;

    Color<double> specular;
    double specularPower;
};
#endif // MATERIAL_H_
