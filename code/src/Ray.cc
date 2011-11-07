#ifndef RAY_TI_H
#define RAY_TI_H
#include "Ray.hpp"

#include <sstream>

using namespace std;

Ray::Ray ( Vector<double, 3> from, Vector<double, 3> to )
: from_(from), to_(to) { }

Ray::Ray ( Vector<double, 3> from, Vector<double, 3> direction, bool Normalize) 
: from_(from) {
  direction_ = ((Normalize) ? direction.Normalized() : direction);
  to_ = direction_ + from;
}

string Ray::pretty () const {
 	stringstream ss;
	ss << "{ From = " << from_ << "; To = " << to_ 
    << "; Direction = " << (to_ - from_).Normalized() << " }"; 

  return ss.str();
}

Vector<double, 3> Ray::from() const { return from_; }
Vector<double, 3> Ray::to() const { return to_; }
Vector<double, 3> Ray::direction() const { return direction_; }
#endif // RAY_TI_H
