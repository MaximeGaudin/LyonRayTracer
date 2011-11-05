#include "Material.hpp"

  Material::Material ( )
  : ambient_(Color<double>(0.03))
  , opacity_ (1)
  , IOR_ (1)
  , reflexivity_(1)
  , diffuse_(Color<double>(0.5))
  , diffuseIntensity_(1)
  , specular_(Color<double>(1))
    , specularPower_(60) 
{ }

  Material::Material ( Color<double> ambient )
  : ambient_(ambient)
  , opacity_ (1)
  , IOR_ (1)
  , reflexivity_(1)
  , diffuse_(Color<double>(0.5))
  , diffuseIntensity_(1)
  , specular_(Color<double>(1))
    , specularPower_(60) 
{ }


  Material::Material ( Color<double> ambient, Color<double> diffuse, Color<double> specular )
  : ambient_(ambient)
  , opacity_ (1)
  , IOR_ (1)
  , reflexivity_(1)
  , diffuse_(diffuse)
  , diffuseIntensity_(1)
  , specular_(specular)
    , specularPower_(60) 
{ }


