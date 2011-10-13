#ifndef VECTOR_TI_H
#define VECTOR_TI_H
#include "Vector.hpp"
#include <exceptions.hpp>

#include <cmath>
#include <sstream>
#include <boost/static_assert.hpp>

typedef Vector<double, 2> Vector2d;
typedef Vector<double, 3> Vector3d;
typedef Vector<double, 4> Vector4d;

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
Vector<P, N>::Vector(const Vector<P, N>& v) { 
  for( int i = 0; i < N; ++i) _values[i] = v._values[i]; 
}

/* Worker Methods =========================================================== */
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
string Vector<P, N >::pretty () const {
  stringstream ss;
  ss << "( ";
  for( int i = 0; i < N; ++i )
    ss << _values[i] << (( i == N - 1 ) ? " )" : " ," );

  return ss.str();
}

/* Operators */
template <typename P, int N>
Vector<P, N> Vector<P, N>::operator + ( const Vector<P, N>& v2 ) const {
  Vector <P, N> result ( v2 );
  Vector <P, N> copy ( *this );
  for( int i = 0; i < N; ++i ) result [i] += copy[i];

  return result;
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
template <typename P, int N >
P& Vector<P, N >::operator [] ( int i ) {
  if ( i >= N ) logException ( VECTOR_OUT_OF_BOUNDS_EXCEPTION_MESSAGE );
  return _values[i];
}

///* Tool methods */
template <typename P, int N>
void Vector<P, N>::checkType () const {
  BOOST_STATIC_ASSERT 	( 
      (boost::is_same < P, float >::type::value) 
      || (boost::is_same <P, double>::type::value) 
      || (boost::is_same <P, int>::type::value)
      || (boost::is_same <P, char>::type::value)
      );
}


///* Getters & setters */
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
#endif
