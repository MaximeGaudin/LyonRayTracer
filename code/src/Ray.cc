#ifndef RAY_TI_H
#define RAY_TI_H
#include "Ray.hpp"

#include <sstream>

using namespace std;

template <typename P, int N>
Ray<P, N>::Ray ( Vector<P, N> from, Vector<P, N> to )
: from_(from), to_(to) { }

template <typename P, int N>
Ray<P, N>::Ray ( Vector<P, N> from, Vector<P, N> direction, bool Normalize) 
: from_(from) {
  to_ = ((Normalize) ? direction.Normalized() : direction) + from;
}

template <typename P, int N>
string Ray<P, N>::pretty () const {
 	stringstream ss;
	ss << "{ From = " << from_ << "; To = " << to_ << "; Direction = " << (to_ - from_) << " }"; 

  return ss.str();
}

template <typename P, int N>
Vector<P, N> Ray<P, N>::from() const { return from_; }

template <typename P, int N>
Vector<P, N> Ray<P, N>::to() const { return to_; }

template <typename P, int N>
Vector<P, N> Ray<P, N>::direction() const { return (to_ - from_).Normalized(); }
#endif // RAY_TI_H
