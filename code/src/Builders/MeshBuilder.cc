#include "MeshBuilder.hpp"
#include <Vector.hpp>
#include <Mesh.hpp>
#include <Material.hpp>

#include <MeshImporters.hpp>

MeshBuilder::MeshBuilder () :
  Builder ( "mesh" )
{ }

Buildable* MeshBuilder::getObject ( 
    boost::property_tree::ptree pt,
    Material* material ) const
{
  Vector3d position; 
  position[0] = pt.get<double>("position.vector3.<xmlattr>.X", 0.0);
  position[1] = pt.get<double>("position.vector3.<xmlattr>.Y", 0.0);
  position[2] = pt.get<double>("position.vector3.<xmlattr>.Z", 0.0);

  Vector3d rotation; 
  rotation[0] = pt.get<double>("rotation.vector3.<xmlattr>.X", 0.0);
  rotation[1] = pt.get<double>("rotation.vector3.<xmlattr>.Y", 0.0);
  rotation[2] = pt.get<double>("rotation.vector3.<xmlattr>.Z", 0.0);

  Vector3d scale; 
  scale[0] = pt.get<double>("scale.vector3.<xmlattr>.X", 1.0);
  scale[1] = pt.get<double>("scale.vector3.<xmlattr>.Y", 1.0);
  scale[2] = pt.get<double>("scale.vector3.<xmlattr>.Z", 1.0);

  std::string filename = pt.get<std::string>("filename");

  logInformation ("MeshBuilder", str( 
        format("New mesh (%1%) at %2%") % filename % position ) );

  MeshImporter3ds MI;
  return MI.build ( filename, material, position, rotation, scale );
}
