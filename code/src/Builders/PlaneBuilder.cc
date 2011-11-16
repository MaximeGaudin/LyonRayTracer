#include "PlaneBuilder.hpp"
#include <Vector.hpp>
#include <Plane.hpp>
#include <Material.hpp>

PlaneBuilder::PlaneBuilder () :
  Builder ( "plane" )
{ }

Buildable* PlaneBuilder::getObject ( 
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

  logInformation ("PlaneBuilder", str( 
        format("New plane at %1% (normal= %2%)") % point % normal ) );
  return new Plane ( point, normal, material );
}
