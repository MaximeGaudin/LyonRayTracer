#include "MaterialBuilder.hpp"
#include <string>

#include <Vector.hpp>
#include <Material.hpp>
#include <ImageFactory.hpp>

MaterialBuilder::MaterialBuilder () :
  Builder ( "material" )
{ }

Buildable* MaterialBuilder::getObject( 
    boost::property_tree::ptree pt,
    Material* material ) const 
{
double R, G, B;

R = pt.get<double>("diffuse.color.<xmlattr>.R", 0.3);
G = pt.get<double>("diffuse.color.<xmlattr>.G", 0.3);
B = pt.get<double>("diffuse.color.<xmlattr>.B", 0.3);
Color_d diffuse ( R, G, B );

R = pt.get<double>("ambient.color.<xmlattr>.R", 0.1);
G = pt.get<double>("ambient.color.<xmlattr>.G", 0.1);
B = pt.get<double>("ambient.color.<xmlattr>.B", 0.1);
Color_d ambient ( R, G, B );

R = pt.get<double>("specular.color.<xmlattr>.R", 1.0);
G = pt.get<double>("specular.color.<xmlattr>.G", 1.0);
B = pt.get<double>("specular.color.<xmlattr>.B", 1.0);
Color_d specular ( R, G, B );

Material* result = new Material ( );
result->diffuse = diffuse;
result->ambient = ambient;
result->specular = specular;

result->opacity = pt.get<double>("opacity", 1.0);
result->reflexivity = pt.get<double>("reflexivity", 0.2);
result->IOR = pt.get<double>("IOR", 1.5);
result->specularPower = pt.get<double>("specularPower", 60);
result->diffuseIntensity = pt.get<double>("diffuseIntensity", 1.5);

std::string textureFilename = pt.get<std::string>("texture", "");
result->hasTexture = false; 
if ( !textureFilename.empty() ) {
  result->texture = ImageFactory::Load ( textureFilename );
  if(result->texture != NULL) result->hasTexture = true;
} 

logInformation ("MaterialBuilder", 
    str ( format ( "New material with diffuse = %1%." )
      % diffuse ));
return result;
}
