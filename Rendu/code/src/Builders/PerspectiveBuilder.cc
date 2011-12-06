#include "PerspectiveBuilder.hpp"
#include <Vector.hpp>
#include <Perspective.hpp>
#include <Material.hpp>

PerspectiveBuilder::PerspectiveBuilder () :
  Builder ( "perspective" )
{ }

Buildable* PerspectiveBuilder::getObject ( 
    boost::property_tree::ptree pt,
    Material* material ) const
{
  Vector3d eye; 
  eye[0] = pt.get<double>("eye.vector3.<xmlattr>.X");
  eye[1] = pt.get<double>("eye.vector3.<xmlattr>.Y");
  eye[2] = pt.get<double>("eye.vector3.<xmlattr>.Z");

  Vector3d lookat; 
  lookat[0] = pt.get<double>("lookat.vector3.<xmlattr>.X");
  lookat[1] = pt.get<double>("lookat.vector3.<xmlattr>.Y");
  lookat[2] = pt.get<double>("lookat.vector3.<xmlattr>.Z");

  Vector3d up; 
  up[0] = pt.get<double>("up.vector3.<xmlattr>.X");
  up[1] = pt.get<double>("up.vector3.<xmlattr>.Y");
  up[2] = pt.get<double>("up.vector3.<xmlattr>.Z");

  double focalDistance = pt.get<double>("focalDistance", 1.0);

  return new Perspective ( focalDistance, eye, lookat, up );
}
