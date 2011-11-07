#include "Perspective.hpp"
#include <Matrix.hpp>

#define _USE_MATH_DEFINES
#include <cmath>

#include <iostream>

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
  const double FoVX = M_PI / 2.0;
  const double FoVY = FoVX * ( (double)resY_ / (double)resX_ );

  const double UpperLeftCornerX = SCREEN_DISTANCE * tan ( FoVX / 2.0 );
  const double UpperLeftCornerY = SCREEN_DISTANCE * tan ( FoVY / 2.0 );
  const double LowerRightCornerX = -UpperLeftCornerX;
  const double LowerRightCornerY = -UpperLeftCornerY;

  const double StepX = (LowerRightCornerX - UpperLeftCornerX) / resX_;
  const double StepY = (LowerRightCornerY - UpperLeftCornerY) / resY_;

  const Vector3d rotationAxix ( Vector3d::Cross ( V3d_Z, direction ) );
  const double rotationAngle = acos ( Vector3d::Dot ( V3d_Z, direction ) / direction.Length() );

  const Matrix < double, 4, 4 > transformation = 
    Matrix<double,4,4>::RotationFromAxis ( rotationAxix, rotationAngle );

  cout << "Direction : " << direction << endl;
  cout << rotationAngle << endl;
  cout << rotationAxix << endl;

  for ( unsigned int Y = 0; Y < resY_; ++Y ) {
    for ( unsigned int X = 0; X < resX_; ++X ) {
      Vector3d position;
      position[0] = UpperLeftCornerX + X * StepX;
      position[1] = UpperLeftCornerY + Y * StepY;
      position[2] = SCREEN_DISTANCE;

  //    cout << position << endl;

      Vector < double, 4 > currentRayDir (  transformation * position.Homogenous() );
      Vector < double, 3 > truncatedVector; 
      for ( unsigned int i = 0; i < 3; ++i ) truncatedVector[i] = currentRayDir[i];

      rayCollection_.push_back ( Ray ( eye, truncatedVector, true ) );

      /*
      cout << direction << endl;
      cout << currentRayDir << endl;
      cout << truncatedVector << endl;
      cout << rayCollection_[rayCollection_.size() - 1] << endl;
      */
    }
  }
}
