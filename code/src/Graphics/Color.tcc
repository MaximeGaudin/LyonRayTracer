#ifndef COLOR_TI_H_
#define COLOR_TI_H_
#include <sstream>

using namespace std;

typedef Color<double> Color_d;

const Color_d Color_d_WHITE ( 1.0 );
const Color_d Color_d_BLACK ( 0.0 );
const Color_d Color_d_BLUE ( 0.0, 0.0, 1.0 );

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

// Worker methods
template < typename P >
Color<P> Color<P>::Clamped () const {
  Color<P> result ( *this );

  result.r_ = ( result.r_ < 0 ) ? 0 : result.r_;
  result.g_ = ( result.g_ < 0 ) ? 0 : result.g_;
  result.b_ = ( result.b_ < 0 ) ? 0 : result.b_;

  P max = ( r_ > g_ ) ? r_ : g_;
  max = ( max > b_ ) ? max : g_;

  if ( max > 1 ) {
    result.r_ /= max;
    result.g_ /= max;
    result.b_ /= max;
  }

  return result;
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


template < typename P >
Color<P>& Color<P>::operator += ( Color<P> const& C2 ) {
  r_ += C2.r_;
  g_ += C2.g_;
  b_ += C2.b_;

  return *this;
}

template < typename P >
Color<P>& Color<P>::operator *= ( Color<P> const& C2 ) {
  r_ *= C2.r_;
  g_ *= C2.g_;
  b_ *= C2.b_;

  return *this;
}

template < typename P >
Color<P>& Color<P>::operator *= ( P const& C2 ) {
  r_ *= C2;
  g_ *= C2;
  b_ *= C2;

  return *this;
}

template < typename P >
Color<P>& Color<P>::operator [] ( unsigned int i ) { 
  switch ( i % 3 ) {
    case ( 0 ): return r_;
    case ( 1 ): return g_;
    case ( 2 ): return b_;
    default: return r_;
  }
}

template < typename P >
Color<P>& Color<P>::operator [] ( unsigned int i ) const { 
  return (*this)[i];
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
