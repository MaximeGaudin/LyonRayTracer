#ifndef VECTOR_H_
#define VECTOR_H_
#include <string>
#include <ostream>
#include <boost/type_traits.hpp>

using namespace std;

template <typename P, int N >
class Vector {
	public:
    /** 
      * Constructeur par défaut, initialise toutes les composantes à 0;
      */
		Vector ();

    /**
      * Initialise toutes les composantes à v
      */
		Vector (P v);

    /**
      * Constructeur de copie, initialise toutes les composantes à la même 
      * valeur que le vecteur de même taille passé en paramètre.
      *
      * @param v Vecteur à copier.
      */
		Vector (const Vector<P, N>& v);

	public:
    /**
      * Renvoie la taille du vecteur calculé comme la racine du produit
      * scalaire du vecteur avec lui même.
      */
		P Length () const;

    /** 
      * Renvoie la taille du vecteur au carré
      */
		P SquaredLength () const;

    /**
      * Renvoie la versione normalisée du vecteur (i.e. de taille unitaire)
      */
		Vector<P, N> Normalized () const;

		string pretty () const;

	public:
    /**
      * Renvoie la produit scalaire des deux vecteurs passés en 
      * paramètre
      */
		static P Dot ( const Vector<P, N>& v1, const Vector<P, N>& v2 );

    /**
      * Renvoie le produit vectoriel de deux vecteur de dimension 3
      */
		static Vector<P, 3> Cross 
      ( const Vector<P, 3>& v1, const Vector<P, 3>& v2 );

	public:
		Vector<P, N> operator + ( const Vector<P, N>& v2 ) const;

		Vector<P, N> operator - ( ) const;
		Vector<P, N> operator - ( const Vector<P, N>& v2 ) const;

		P& operator [] ( int i );

		friend ostream &operator << (ostream& oss, const Vector<P, N >& v) const {
      oss << v.pretty();
      return oss;
    }

	public:
    /**
      * Renvoie la valeur de la première composante
      */
		P X() const;

    /**
      * Renvoie la valeur de la secondes composante si elle existe.
      * Si la composante n'existe pas, la compilation est interrompue.
      */
		P Y() const;

    /**
      * Renvoie la valeur de la troisième composante si elle existe.
      * Si la composante n'existe pas, la compilation est interrompue.
      */
		P Z() const;

    /**
      * Renvoie la valeur de la quatrième composante si elle existe.
      * Si la composante n'existe pas, la compilation est interrompue.
      */
		P T() const;

	private:
		void checkType () const;

	protected:
		P _values [N];
};
#endif // VECTOR_H_
