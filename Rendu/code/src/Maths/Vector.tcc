#ifndef VECTOR_TI_H_
#define VECTOR_TI_H_
#include <exceptions.hpp>

#include <cmath>
#include <sstream>
#include <boost/static_assert.hpp>

#include <iostream>

#define  VECTOR_OUT_OF_BOUNDS_EXCEPTION_MESSAGE "Out of bound."

using namespace std;

typedef Vector<double, 2> Vector2d;
typedef Vector<double, 3> Vector3d;
typedef Vector<double, 4> Vector4d;

const Vector3d V3d_Zero     ( 0.0, 0.0, 0.0 );
const Vector3d V3d_One      ( 1.0, 1.0, 1.0 );

const Vector3d V3d_X        ( 1.0, 0.0, 0.0 );
const Vector3d V3d_Y        ( 0.0, 1.0, 0.0 );
const Vector3d V3d_Z        ( 0.0, 0.0, 1.0 );

const Vector3d V3d_Up       ( 0.0, 1.0, 0.0 );
const Vector3d V3d_Down     ( 0.0, -1.0, 0.0 );
const Vector3d V3d_Left     ( -1.0, 0.0, 0.0 );
const Vector3d V3d_Right    ( 1.0, 0.0, 0.0 );
const Vector3d V3d_Forward  ( 0.0, 0.0, -1.0 );
const Vector3d V3d_Backward ( 0.0, 0.0, 1.0 );

/* Ctor */
template <typename P, int N>
Vector<P, N>::Vector () {
  checkType();
  for( int i = 0; i < N; ++i) _values[i] = static_cast<P>(0);
}


template <typename P, int N>
Vector<P, N>::Vector (P v) {
  checkType();
  for( int i = 0; i < N; ++i) _values[i] = v;
}


template <typename P, int N>
Vector <P, N>::Vector ( P const& X, P const& Y, P const& Z ) {
  BOOST_STATIC_ASSERT ( N >= 3 );
  _values[0] = X;
  _values[1] = Y;
  _values[2] = Z;
}

template <typename P, int N>
Vector<P, N>::Vector(const Vector<P, N>& v) { 
  for( int i = 0; i < N; ++i) _values[i] = v._values[i]; 
}

/* Worker Methods */
template <typename P, int N >
P Vector<P, N >::Length () const {
  P acc = 0;

  for( int i = 0; i < N; ++i) acc += (_values[i] * _values[i]);
  return sqrt ( acc );
}

template <typename P, int N >
P Vector<P, N >::SquaredLength () const {
  P acc = 0;

  for( int i = 0; i < N; ++i) acc += (_values[i] * _values[i]);
  return acc;
}

template <typename P, int N >
Vector<P, N > Vector<P, N >::Normalized () const {
  Vector<P, N > newVector;
  P length = this->Length();

  for ( int i = 0; i < N; ++i ) newVector[i] = _values[i] / length;
  return newVector;
}

template <typename P, int N >
Vector<P, 4 > Vector<P, N >::Homogenous() const {
  Vector<P, 4 > newVector;

  for ( int i = 0; i < 3; ++i ) newVector[i] = _values[i]; 
  newVector[3] = 1;

  return newVector;
}

template <typename P, int N >
Vector<P, N> Vector<P,N>::Project ( Vector<P, N> const& v2 ) const {
  Vector<P, N> newVector ( *this );

  for ( int i = 0; i < N; ++i ) newVector[i] *= v2[i]; 
  return newVector;
}

template <typename P, int N >
string Vector<P, N >::pretty () const {
  stringstream ss;
  ss << "( ";
  for( int i = 0; i < N; ++i )
    ss << _values[i] << (( i == N - 1 ) ? " )" : " ," );

  return ss.str();
}

// Static methods
template <typename P, int N>
P Vector<P,N>::Dot ( const Vector<P, N>& v1, const Vector<P, N>& v2 ) {
  double dotProduct = 0;
  for(unsigned int i = 0; i < N; ++i )
    dotProduct += v1[i] * v2[i];

  return dotProduct;
}

template <typename P, int N>
Vector<P,3> Vector<P,N>::Cross ( const Vector<P, 3>& v1, const Vector<P, 3>& v2 ) {
  Vector<P,3> result;

  result [0] = v1[1]*v2[2] - v1[2]*v2[1];
  result [1] = v1[2]*v2[0] - v1[0]*v2[2];
  result [2] = v1[0]*v2[1] - v1[1]*v2[0];

  return result;
}

/* Operators */

template <typename P, int N>
bool Vector<P,N>::operator == ( Vector<P,N> const& v2 ) const
{
  for ( unsigned int i = 0; i < N; ++i ) 
    if ( _values[i] != v2[i] ) return false;

  return true;
}

template <typename P, int N>
bool Vector<P,N>::operator != ( Vector<P,N> const& v2 ) const
{
  return !(*this == v2);
}

template <typename P, int N>
Vector<P, N> Vector<P, N>::operator + ( const Vector<P, N>& v2 ) const {
  Vector <P, N> result ( v2 );
  Vector <P, N> copy ( *this );
  for( int i = 0; i < N; ++i ) result [i] += copy[i];

  return result;
}

template <typename P, int N>
Vector<P, N>& Vector<P, N>::operator += ( const Vector<P, N>& v2 ) {
  *this = *this + v2;
  return *this;
}

template <typename P, int N>
Vector<P, N> Vector<P, N>::operator - ( ) const {
  Vector <P, N> result ( *this );
  for( int i = 0; i < N; ++i ) result [i] = -result[i];

  return result;
}

template <typename P, int N>
Vector<P, N> Vector<P, N>::operator - ( const Vector<P, N>& v2 ) const {
  Vector<P, N> result ( *this );
  return result + ( - v2 );
}

template <typename P, int N>
Vector<P, N> Vector<P, N>::operator * ( double const& d ) const {
  Vector<P, N> result ( *this );
  for ( unsigned int i = 0; i < N; ++i ) result[i] *= d;

  return result;
}

template <typename P, int N>
Vector<P, N> Vector<P, N>::operator / ( double const& d ) const {
  return (*this) * (1.0/d);
}

template <typename P, int N>
Vector<P, N>& Vector<P, N>::operator /= ( double const& d ) {
  *this = *this / d;
  return *this;
}
template <typename P, int N >
P& Vector<P, N >::operator [] ( unsigned int i ) {
  if ( i >= N ) logException ( VECTOR_OUT_OF_BOUNDS_EXCEPTION_MESSAGE );
  return _values[i];
}

template <typename P, int N >
P const& Vector<P, N >::operator [] ( unsigned int i ) const {
  if ( i >= N ) logException ( VECTOR_OUT_OF_BOUNDS_EXCEPTION_MESSAGE );
  return _values[i];
}

/* Tool methods */
template <typename P, int N>
void Vector<P, N>::checkType () const {
  BOOST_STATIC_ASSERT 	( 
      (boost::is_same < P, float >::type::value) 
      || (boost::is_same <P, double>::type::value) 
      || (boost::is_same <P, int>::type::value)
      || (boost::is_same <P, char>::type::value)
      );
}

/* Getters & setters */
template <typename P,int N> P Vector<P, N>::X() const {
  BOOST_STATIC_ASSERT ( N >= 1 );
  return _values[0];
}

template <typename P,int N> P Vector<P, N>::Y() const {
  BOOST_STATIC_ASSERT ( N >= 2 );
  return _values[1];
}


template <typename P,int N> P Vector<P, N>::Z() const {
  BOOST_STATIC_ASSERT ( N >= 3 );
  return _values[2];
}

template <typename P,int N> P Vector<P, N>::T() const {
  BOOST_STATIC_ASSERT ( N >= 4);
  return _values[3];
}
#endif // VECTOR_TI_H_
