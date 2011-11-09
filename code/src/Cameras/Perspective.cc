#include "Perspective.hpp"
#include <Matrix.hpp>
#include <exceptions.hpp>


#define _USE_MATH_DEFINES
#include <cmath>

#include <iostream>

using namespace std;

// Ctors

Perspective::Perspective (
    double focaleDistance,
    Vector3d eye,
    Vector3d lookAt,
    Vector3d up )
  : focaleDistance_(focaleDistance)
  , eye_(eye)
  , lookAt_(lookAt)
    , up_(up)
{
  IPNormal_ = (lookAt_ - eye).Normalized();
  if ( IPNormal_ != V3d_Up ) IPXAxis_ = Vector3d::Cross ( IPNormal_, V3d_Up ).Normalized(); 
  else IPXAxis_ = Vector3d::Cross ( IPNormal_, V3d_Left ).Normalized(); 

  IPYAxis_ = Vector3d::Cross ( IPNormal_, IPXAxis_ ).Normalized(); 
  IPZAxis_ = Vector3d::Cross ( IPXAxis_, IPYAxis_ ).Normalized(); 

  logInformation ( "Perspective", str( format("New Camera : Eye - %1%, LookAt - %2%, \
          Direction %3%") % eye_.pretty() % lookAt_.pretty() % IPNormal_.pretty() ) );
}

Ray Perspective::getRay ( double u, double v ) const { 
  Ray r  ( eye_, IPNormal_ * focaleDistance_
      + IPXAxis_ * (u - 0.5)
      + IPYAxis_ * (v - 0.5), true );

  return r;
}
