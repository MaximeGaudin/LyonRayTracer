#ifndef MATRIX_TI_H
#define MATRIX_TI_H
#include "Matrix.hpp"

#include <cmath>
#include <sstream>

using namespace std;

// Ctors
template < typename P, int N, int M >
Matrix < P, N, M >::Matrix ( MATRIX_TYPE type ) {
  for ( unsigned int i = 0; i < N; ++i ) 
    for ( unsigned int j = 0; j < M; ++j )
      values_[i][j] = ( i == j ) ? type : 0;

}

template < typename P, int N, int M >
Matrix < P, N, M >::Matrix ( const Matrix < P, N, M >& m ) {
  for ( unsigned int i = 0; i < N; ++i ) 
    for ( unsigned int j = 0; j < M; ++j )
      values_[i][j] = m.values_[i][j];
}

// Operators
template < typename P, int N, int M >
P* Matrix < P, N, M >::operator [] ( int i ) {
  return values_[i];
}

template < typename P, int N, int M >
Matrix < P, N, M > Matrix < P, N, M >::operator * ( const Matrix < P, N, M >& m ) const {
  Matrix < P, N, M > result ( ZERO );

  for ( unsigned int i = 0; i < N; ++i ) 
    for ( unsigned int j = 0; j < M; ++j )
      for ( unsigned int k = 0; k < M; ++k ) 
        result[i][j] += values_[i][k] * m.values_[k][j];

  return result;
}

// Transformation matrices
template < typename P, int N, int M >
Matrix < P, 4, 4 > Matrix < P, N, M >::RotationX ( double angle ) {
  Matrix < P, 4, 4 > result ( IDENTITY ); 

  result[1][1] = cos(angle);
  result[2][1] = -sin(angle);
  result[1][2] = sin(angle);
  result[2][2] = cos(angle);

  return result;
}

template < typename P, int N, int M >
Matrix < P, 4, 4 > Matrix < P, N, M >::RotationY ( double angle ) {
  Matrix < P, 4, 4 > result ( IDENTITY ); 

  result[0][0] = cos(angle);
  result[2][0] = sin(angle);
  result[0][2] = -sin(angle);
  result[2][2] = cos(angle);

  return result;
}

template < typename P, int N, int M >
Matrix < P, 4, 4 > Matrix < P, N, M >::RotationZ ( double angle ) {
  Matrix < P, 4, 4 > result ( IDENTITY ); 

  result[0][0] = cos(angle);
  result[1][0] = -sin(angle);
  result[0][1] = sin(angle);
  result[1][1] = cos(angle);

  return result;
}

template < typename P, int N, int M >
Matrix < P, 4, 4 > Matrix < P, N, M >::Rotation (
    double Xangle, 
    double Yangle, 
    double Zangle ) {
  return Matrix < P, 4, 4 >::RotationX ( Xangle )
    * Matrix < P, 4, 4 >::RotationY ( Yangle )
    * Matrix < P, 4, 4 >::RotationZ ( Zangle );
}

// Pretty printing
string generateSpaces ( int n ) {
  string spaces;

  while ( n-- ) spaces.append( " " );
  return spaces;
}

unsigned int getNumberSize ( double N ) {
  stringstream ss;
  ss << N;

  return ss.str().length();
}

template < typename P, int N, int M > 
string Matrix < P, N, M >::pretty () const { 
  stringstream result;
  unsigned int maxDigits = 0;

  for ( unsigned int i = 0; i < N; ++i )
    for ( unsigned int j = 0; j < M; ++j )
      maxDigits = max ( maxDigits, getNumberSize(values_[i][j]) );

  for ( unsigned int i = 0; i < N; ++i ) {
    for ( unsigned int j = 0; j < M; ++j ) {
      result << "| ";
      result << generateSpaces ( maxDigits - getNumberSize(values_[i][j]) );
      result << values_[i][j];
    }
    result << "|\n";
  }

  return result.str();
}
#endif // MATRIX_TI_H
