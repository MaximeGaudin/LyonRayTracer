#include "SphereBuilder.hpp"
#include <Vector.hpp>
#include <Sphere.hpp>
#include <Material.hpp>

SphereBuilder::SphereBuilder () :
  Builder ( "sphere" )
{ }

Buildable* SphereBuilder::getObject ( 
    boost::property_tree::ptree pt,
    Material* material ) const
{
  Vector3d centre; 
  centre[0] = pt.get<double>("centre.vector3.<xmlattr>.X");
  centre[1] = pt.get<double>("centre.vector3.<xmlattr>.Y");
  centre[2] = pt.get<double>("centre.vector3.<xmlattr>.Z");

  double radius = pt.get<double>("radius");

  logInformation ("SphereBuilder", str( 
        format("New sphere at %1% (radius = %2%)") % centre % radius ) );
  return new Sphere ( centre, radius, material );
}
