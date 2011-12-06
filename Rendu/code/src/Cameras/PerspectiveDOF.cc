#include "PerspectiveDOF.hpp"
#include <cstdlib>

#include <exceptions.hpp>

// Ctors
PerspectiveDOF::PerspectiveDOF (
    Vector3d const& eye, Vector3d const& lookAt, Vector3d const& up,
    Vector3d const& focusPoint, unsigned int sampling, double aperture ) :
  focaleDistance_(1.0),
  eye_(eye),
  lookAt_(lookAt),
  up_(up),
  focusPoint_(focusPoint),
  sampling_ (sampling),
  aperture_ (aperture),
  focusPlane_( Plane ( V3d_Zero, V3d_Up ) )
{
  setupCameraBase ();
}

PerspectiveDOF::PerspectiveDOF (
    double focaleDistance,
    Vector3d const& eye, Vector3d const& lookAt, Vector3d const& up,
    Vector3d const& focusPoint, unsigned int sampling, double aperture ) :
  focaleDistance_(focaleDistance),
  eye_(eye),
  lookAt_(lookAt),
  up_(up),
  focusPoint_(focusPoint),
  sampling_ (sampling),
  aperture_ (aperture),
  focusPlane_( Plane ( V3d_Zero, V3d_Up ) )
{
  setupCameraBase ();
}

static double drand (double min, double max ) {
  return (max - min) * (rand() / (double)(RAND_MAX)) + min;
}

// Worker methods
void PerspectiveDOF::setupCameraBase ( ) {
  IPNormal_ = (lookAt_ - eye_).Normalized();
  if ( IPNormal_ != V3d_Up ) IPXAxis_ = Vector3d::Cross ( IPNormal_, V3d_Up ).Normalized(); 
  else IPXAxis_ = Vector3d::Cross ( IPNormal_, V3d_Left ).Normalized(); 

  IPYAxis_ = Vector3d::Cross ( IPNormal_, IPXAxis_ ).Normalized(); 
  IPZAxis_ = Vector3d::Cross ( IPXAxis_, IPYAxis_ ).Normalized(); 

  focusPlane_ = Plane ( focusPoint_, -IPNormal_ );

  logInformation ( "PerspectiveDOF", 
      str( format("New Camera : Eye - %1%, LookAt - %2%, Direction %3%") 
        % eye_.pretty() % lookAt_.pretty() % IPNormal_.pretty() ) );
}

std::vector< Ray > PerspectiveDOF::getRay ( double u, double v ) const { 
  std::vector < Ray > cameraRays;

  Ray clearRay  ( eye_, IPNormal_ * focaleDistance_
      + IPXAxis_ * (u - 0.5)
      + IPYAxis_ * (v - 0.5) );

  Vector3d DisturbedEye;
  DisturbedEye[2] = eye_[2];

  for(unsigned int i = 0; i < sampling_; ++i ) {
    DisturbedEye[0] = eye_[0] + drand(-1, 1) * drand(0.0,1.0)* aperture_;
    DisturbedEye[1] = eye_[1] + drand(-1, 1) * drand(0.0,1.0)* aperture_;

    Vector3d clearPoint = focusPlane_.getRecord ( clearRay ).position;

    Ray r  ( DisturbedEye, (clearPoint - DisturbedEye).Normalized() );
    cameraRays.push_back( r );
  }
  return cameraRays;
}
