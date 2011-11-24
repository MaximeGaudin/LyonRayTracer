#include "PerspectiveDOFBuilder.hpp"
#include <Vector.hpp>
#include <PerspectiveDOF.hpp>
#include <Material.hpp>

PerspectiveDOFBuilder::PerspectiveDOFBuilder () :
  Builder ( "perspectiveDOF" )
{ }

Buildable* PerspectiveDOFBuilder::getObject ( 
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

  Vector3d focusPoint; 
  focusPoint[0] = pt.get<double>("focusPoint.vector3.<xmlattr>.X");
  focusPoint[1] = pt.get<double>("focusPoint.vector3.<xmlattr>.Y");
  focusPoint[2] = pt.get<double>("focusPoint.vector3.<xmlattr>.Z");

  double focalDistance = pt.get<double>("focalDistance", 1.0);
  unsigned int sampling = pt.get<double>("sampling", 4);
  double aperture= pt.get<double>("aperture", 1.0);

  return new PerspectiveDOF ( focalDistance, eye, lookat, up, 
      focusPoint, sampling, aperture );
}
