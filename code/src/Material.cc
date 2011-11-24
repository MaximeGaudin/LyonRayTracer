#include "Material.hpp"
#include <Geometry.hpp>
#include <Image.hpp>

  Material::Material ( )
  : ambient(Color_d(0.03))
  , opacity (1)
  , IOR (1)
  , reflexivity(0.1)
  , diffuse(Color_d(0.5))
  , diffuseIntensity(1)
  , specular(Color_d(1))
    , specularPower(60) 
{ }

  Material::Material ( Color_d diffuse )
  : ambient(Color_d(0.03))
  , opacity (1)
  , IOR (1)
  , reflexivity(0.1)
  , diffuse(diffuse)
  , diffuseIntensity(1)
  , specular(Color_d(1))
    , specularPower(60) 
{ }


  Material::Material ( Color_d ambient, Color_d diffuse, Color_d specular )
  : ambient(ambient)
  , opacity (1)
  , IOR (1)
  , reflexivity(0.1)
  , diffuse(diffuse)
  , diffuseIntensity(1)
  , specular(specular)
    , specularPower(60) 
{ }

Color_d Material::getGeometryColor ( HitRecord const& record ) {
  if ( !record.hitGeometry->material()->hasTexture )
      return record.hitGeometry->material()->diffuse;

  Image* texture = record.hitGeometry->material()->texture;
  Vector <double,2> UV = record.hitGeometry->getUVFromHit ( record );

  return (*texture)[(int)(UV[0] * texture->W())][(int)(UV[1] * texture->H())];
}


