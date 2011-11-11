#ifndef RAY_TI_H
#define RAY_TI_H
#include "Ray.hpp"

#include <sstream>

using namespace std;

Ray::Ray ( Vector3d from, Vector3d to )
: from_(from), to_(to) { }

Ray::Ray ( Vector3d from, Vector3d direction, bool Normalize) 
: from_(from) {
  direction_ = ((Normalize) ? direction.Normalized() : direction);
  for ( unsigned int i = 0; i < 3; ++i ) 
    if ( direction_[i] == -0.0 ) direction_[i] = 0.0;

  to_ = direction_ + from;
}

string Ray::pretty () const {
 	stringstream ss;
	ss << "{ From = " << from_ << ";" 
    << "; Direction = " << (to_ - from_).Normalized() << " }"; 

  return ss.str();
}

Vector3d Ray::from() const { return from_; }
Vector3d Ray::to() const { return to_; }
Vector3d Ray::direction() const { return direction_; }
#endif // RAY_TI_H
