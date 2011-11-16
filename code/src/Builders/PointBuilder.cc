#include "PointBuilder.hpp"
#include <Vector.hpp>
#include <Point.hpp>
#include <Material.hpp>

PointBuilder::PointBuilder () :
  Builder ( "point" )
{ }

Buildable* PointBuilder::getObject ( 
    boost::property_tree::ptree pt,
    Material* material ) const
{
  Vector3d position; 
  position[0] = pt.get<double>("position.vector3.<xmlattr>.X");
  position[1] = pt.get<double>("position.vector3.<xmlattr>.Y");
  position[2] = pt.get<double>("position.vector3.<xmlattr>.Z");

  logInformation ("SphereBuilder", str( 
        format("New point light at %1%") % position ) );

  return new Point ( position, material );
}
