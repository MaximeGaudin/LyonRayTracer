#ifndef MATRIX_H
#define MATRIX_H
#include <string>

using namespace std;

enum MATRIX_TYPE { ZERO = 0, IDENTITY = 1};

template < typename P, int N, int M >
class Matrix {
  public:
    /**
      * Constructeur d'une matrice.
      *
      * @param type Si ZERO, construit une matrice nulle, si IDENTITY, 
      * construit une matrice identité
      */
    Matrix ( MATRIX_TYPE type );

    /**
      * Constructeur de copie d'une matrice.
      */
    Matrix ( const Matrix < P, N, M >& m );

  public:
    string pretty () const;

  public:
    /**
      * Construit une matrice homogène de rotation autours de 
      * l'axe des X (repère main droite).
      *
      * @param angle Angle en radian de la rotation.
      * @return La matrice homogène construite.
      */
    static Matrix < P, 4, 4 > RotationX ( double angle );

      /**
      * Construit une matrice homogène de rotation autours de 
      * l'axe des Y (repère main droite).
      *
      * @param angle Angle en radian de la rotation.
      * @return La matrice homogène construite.
      */
    static Matrix < P, 4, 4 > RotationY ( double angle );

      /**
      * Construit une matrice homogène de rotation autours de 
      * l'axe des Z (repère main droite).
      *
      * @param angle Angle en radian de la rotation.
      * @return La matrice homogène construite.
      */
    static Matrix < P, 4, 4 > RotationZ ( double angle );

      /**
      * Construit une matrice homogène de rotation autours des 
      * 3 axes.
      *
      * @param Xangle Angle en radian de la rotation autours de X.
      * @param Yangle Angle en radian de la rotation autours de Y.
      * @param Zangle Angle en radian de la rotation autours de Z.
      * @return La matrice homogène construite en calculant le produit
      * des trois matrices de rotations.
      */
    static Matrix < P, 4, 4 > Rotation (
           double Xangle, 
           double Yangle, 
           double Zangle );

    /**
      * Construit la matrice homogène de translation.
      *
      * @param X Translation par rapport à l'axe des X ( en repère main droite ).
      * @param Y Translation par rapport à l'axe des Y ( en repère main droite ).
      * @param Z Translation par rapport à l'axe des Z ( en repère main droite ).
      * @return La matrice homogène construite.
      */
    static Matrix < P, 4, 4 > Translation ( 
    double X,
    double Y, 
    double Z );
 
    /**
      * Construit la matrice homogène de mise à l'échelle.
      *
      * @param X Mise à l'échelle par rapport à l'axe des X ( en repère main droite ).
      * @param Y Mise à l'échelle par rapport à l'axe des Y ( en repère main droite ).
      * @param Z Mise à l'échelle par rapport à l'axe des Z ( en repère main droite ).
      * @return La matrice homogène construite.
      */
    static Matrix < P, 4, 4 > Scale ( 
    double X,
    double Y, 
    double Z );

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
