#include "AreaBuilder.hpp"
#include <Vector.hpp>
#include <Area.hpp>
#include <Material.hpp>

AreaBuilder::AreaBuilder () :
  Builder ( "area" )
{ }

Buildable* AreaBuilder::getObject ( 
    boost::property_tree::ptree pt,
    Material* material ) const
{
  Vector3d point; 
  point[0] = pt.get<double>("point.vector3.<xmlattr>.X");
  point[1] = pt.get<double>("point.vector3.<xmlattr>.Y");
  point[2] = pt.get<double>("point.vector3.<xmlattr>.Z");

  Vector3d normal; 
  normal[0] = pt.get<double>("normal.vector3.<xmlattr>.X");
  normal[1] = pt.get<double>("normal.vector3.<xmlattr>.Y");
  normal[2] = pt.get<double>("normal.vector3.<xmlattr>.Z");

  double sizeX = pt.get<double>("sizeX");
  double sizeY = pt.get<double>("sizeY");
  unsigned int sampling = pt.get<unsigned int>("sampling", 8);

  logInformation ("AreaBuilder", str( 
        format("New area light at %1%") % point ) );

  return new Area ( point, normal, sizeX, sizeY, sampling, material );
}
