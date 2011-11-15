#ifndef RAY_TI_H
#define RAY_TI_H
#include "Ray.hpp"

#include <sstream>

Ray::Ray ( Vector3d const& from, Vector3d const& direction ) 
: from_(from)
, direction_(direction.Normalized())
{
  for ( unsigned int i = 0; i < 3; ++i ) 
    if ( direction_[i] == -0.0 ) direction_[i] = 0.0;
}

string Ray::pretty () const {
  std::stringstream ss;
	ss << "{ From = " << from_ << ";" 
    << "; Direction = " << direction_ << " }"; 

  return ss.str();
}

Vector3d Ray::from() const { return from_; }
Vector3d Ray::direction() const { return direction_; }
#endif // RAY_TI_H
