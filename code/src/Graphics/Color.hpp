/**
  * @file Color.hpp
  * @brief Définition de la classe Color.
  * @author Maxime Gaudin
  * @date 2011
  *
  * La classe couleur est paramétrée par le type numérique stockant chaque 
  * composante. Les types autorisés sont :
  * - unsigned char/ char
  * - unsigned short/ short
  * - unsigned int/ int
  * - double
  * - float
  */
#ifndef COLOR_H_
#define COLOR_H_

#include <iostream>
#include <string>

using namespace std;

template < typename P >
class Color {
  public: // Ctors 
    /**
      * Constructeur par défaut. Toutes les composantes de la couleur sont à 0.
      */
    Color ();

    /**
      * Construit une couleur dont toutes les composantes sont mise à v.
      *
      * @param v Valeur de toutes les composantes.
      */
    Color ( P const& v );

    /** 
      * Construit une couleur en fonction des composantes passées en paramètre.
      *
      * @param R Valeur de la composante rouge.
      * @param G Valeur de la composante Verte.
      * @param B Valeur de la composante bleue.
      */
    Color ( P const& R, P const& G, P const &B );

    Color ( Color<P> const& C );

  public:
    string pretty () const;

    Color<P> Clamped () const;

  public:
    Color<P> operator + ( Color <P> const& C2 ) const;
    Color<P> operator + ( P const& C2 ) const;
   
    Color<P> operator - ( Color <P> const& C2 ) const;
    Color<P> operator - ( P const& C2 ) const;

    Color<P> operator * ( Color <P> const& C2 ) const;
    Color<P> operator * ( P const& C2 ) const;

    Color<P>& operator += ( Color<P> const& C2 );

    Color<P>& operator *= ( Color<P> const& C2 ) ;
    Color<P>& operator *= ( P const& C2 ) ;

    Color<P>& operator [] ( unsigned int i );
    Color<P>& operator [] ( unsigned int i ) const;

    friend ostream& operator << (ostream& oss, Color<P> const& c) {
      oss << c.pretty();
      return oss;
    }

  public: // Getters & Setters
   P R() const; 
   P G() const; 
   P B() const; 

  private:
   P r_;
   P g_;
   P b_;
};

#include "Color.tcc"
#endif // COLOR_H_
