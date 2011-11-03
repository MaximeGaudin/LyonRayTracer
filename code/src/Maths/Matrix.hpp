#ifndef MATRIX_H
#define MATRIX_H
#include <string>

using namespace std;

enum MATRIX_TYPE { ZERO = 0, IDENTITY = 1};

template < typename P, int N, int M >
class Matrix {
  public:
    Matrix ( MATRIX_TYPE type );
    Matrix ( const Matrix < P, N, M >& m );

  public:
    string pretty () const;

  public:
    static Matrix < P, 4, 4 > RotationX ( double angle );
    static Matrix < P, 4, 4 > RotationY ( double angle );
    static Matrix < P, 4, 4 > RotationZ ( double angle );
    static Matrix < P, 4, 4 > Rotation (
           double Xangle, 
           double Yangle, 
           double Zangle );

  public:
    P* operator [] ( int i );
    Matrix < P, N, M > operator * ( const Matrix < P, N, M >& m ) const;

    friend ostream &operator << (ostream& oss, const Matrix <P, N, M >& m) const {
      oss << m.pretty();
      return oss;
    }

  private:
    P values_[N][M];
};
#endif // MATRIX_H
