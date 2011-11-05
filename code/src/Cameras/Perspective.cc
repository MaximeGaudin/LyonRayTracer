#include "Perspective.hpp"
#include <Matrix.hpp>

#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;

// Ctors
Perspective::Perspective ( 
    unsigned int resX, unsigned int resY,
    Vector < double, 3 > eye,
    Vector < double, 3 > lookTo,
    Vector < double, 3 > up ) 
: Camera ( resX, resY )
{
  initialize ( eye, (lookTo - eye).Normalized(), up );
}

// Worker methods
void Perspective::initialize (  
    Vector < double, 3 > eye,
    Vector < double, 3 > direction,
    Vector < double, 3 > up )
{
  const double SCREEN_DISTANCE = 1.0;

  Vector < double, 2 > FoV; 
  FoV[0] = M_PI / 4.0; FoV[1] =  FoV[0] * resY_ / resX_;

  Vector < double, 2 > step; 
  step[0] = (2.0 * FoV[0]) / resX_; step[1] = (2.0 * FoV[1]) / resX_;

  Matrix < double, 4, 4 > cameraTransformation ( ZERO );
  double angleX = -1.0 * atan(direction[1] / direction[2]);
  double angleY = atan(direction[0] / direction[2]);
  double angleZ = 0; // TODO
  cameraTransformation = Matrix < double, 4, 4 >::Rotation ( angleX, angleY, angleZ );

  for ( unsigned int Y = 0; Y < resY_; ++Y ) {
    for ( unsigned int X = 0; X < resX_; ++X ) {
      double RelativeX = X - resX_ / 2.0;
      double RelativeY = -1.0 * (Y - resY_ / 2.0);

      Vector < double, 3 > absoluteDirection;
      absoluteDirection[0] = RelativeX * step[0];
      absoluteDirection[1] = RelativeY * step[1];
      absoluteDirection[2] = SCREEN_DISTANCE;

      Vector < double, 4 > currentRayDir (  cameraTransformation * absoluteDirection.Homogenous() );
      Vector < double, 3 > truncatedVector; 
      for ( unsigned int i = 0; i < 3; ++i ) truncatedVector[i] = currentRayDir[i];

      rayCollection_.push_back ( Ray ( eye, truncatedVector, true ) );
    }
  }
}
