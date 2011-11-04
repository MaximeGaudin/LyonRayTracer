#ifndef COLOR_TI_H_
#define COLOR_TI_H_

#include "Color.hpp"

#include <sstream>

using namespace std;

// Ctors
template < typename P >
Color<P>::Color ( ) 
  : r_(0)
  , g_(0)
    , b_(0)
{ }


template < typename P >
Color<P>::Color ( P const& v ) 
  : r_(v)
  , g_(v)
    , b_(v)
{ }

template < typename P >
Color<P>::Color ( P const& R, P const& G, P const &B )
  : r_(R)
  , g_(G)
    , b_(B)
{ }

template < typename P >
Color<P>::Color ( Color<P> const& C ) {
  r_ = C.r_;
  g_ = C.g_;
  b_ = C.b_;
}

// Operators
template < typename P >
Color<P> Color<P>::operator + ( Color <P> const& C2 ) const {
  Color<P> result ( *this );
  result.r_ += C2.r_;
  result.g_ += C2.g_;
  result.b_ += C2.b_;

  return result;
}
template < typename P >
Color<P> Color<P>::operator + ( P const& C2 ) const {
  Color<P> result ( *this );
  result.r_ += C2;
  result.g_ += C2;
  result.b_ += C2;

  return result;
}

template < typename P >
Color<P> Color<P>::operator - ( Color <P> const& C2 ) const {
  Color<P> result ( *this );
  result.r_ -= C2.r_;
  result.g_ -= C2.g_;
  result.b_ -= C2.b_;

  return result;
}
template < typename P >
Color<P> Color<P>::operator - ( P const& C2 ) const {
  Color<P> result ( *this );
  result.r_ -= C2;
  result.g_ -= C2;
  result.b_ -= C2;

  return result;
}

template < typename P >
Color<P> Color<P>::operator * ( Color <P> const& C2 ) const {
  Color<P> result ( *this );
  result.r_ *= C2.r_;
  result.g_ *= C2.g_;
  result.b_ *= C2.b_;

  return result;
}
template < typename P >
Color<P> Color<P>::operator * ( P const& C2 ) const {
  Color<P> result ( *this );
  result.r_ *= C2;
  result.g_ *= C2;
  result.b_ *= C2;

  return result;
}

// Getters
template < typename P >
P Color<P>::R() const { return r_; }

template < typename P >
P Color<P>::B() const { return b_; }

template < typename P >
P Color<P>::G() const { return g_; }

// Tool methods 
template < typename P >
string Color<P>::pretty () const {
  stringstream ss;
  ss << "[ R=" << r_;
  ss << ", G=" << g_;
  ss << ", B=" << b_;
  ss << " ]";

  return ss.str();
}
#endif // COLOR_TI_H_
