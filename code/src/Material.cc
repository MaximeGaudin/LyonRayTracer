#include "Material.hpp"

  Material::Material ( )
  : ambient(Color<double>(0.03))
  , opacity (1)
  , IOR (1)
  , reflexivity(0.1)
  , diffuse(Color<double>(0.5))
  , diffuseIntensity(1)
  , specular(Color<double>(1))
    , specularPower(60) 
{ }

  Material::Material ( Color<double> diffuse )
  : ambient(Color<double>(0.03))
  , opacity (1)
  , IOR (1)
  , reflexivity(0.1)
  , diffuse(diffuse)
  , diffuseIntensity(1)
  , specular(Color<double>(1))
    , specularPower(60) 
{ }


  Material::Material ( Color<double> ambient, Color<double> diffuse, Color<double> specular )
  : ambient(ambient)
  , opacity (1)
  , IOR (1)
  , reflexivity(0.1)
  , diffuse(diffuse)
  , diffuseIntensity(1)
  , specular(specular)
    , specularPower(60) 
{ }


