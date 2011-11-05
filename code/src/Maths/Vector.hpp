/**
  * @file Vector.hpp
  * @brief Header de la classe Vector.
  * @author Maxime Gaudin
  * @date 2011
  *
  * La classe Vector dépend de 2 paramètres template :
  * - P : Le type numérique à stocker.
  * - N : Le nombre de lignes du vecteur.
  *
  * Les types numériques acceptés sont :
  * - unsigned char / char
  * - unsigned short / short 
  * - unsigned int / int 
  * - float
  * - double
  * - long
  * - long X
  */ 
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
      *
      * @param v Valeur de toutes les composantes.
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
      *
      * @return Taille du vecteur.
      */
		P Length () const;

    /** 
      * Renvoie la taille du vecteur au carré.
      *
      * @return Taille du vecteur au carré.
      */
		P SquaredLength () const;

    /**
      * Renvoie la versione normalisée du vecteur (i.e. de taille unitaire).
      *
      * @return Vecteur normalisé.
      */
		Vector<P, N> Normalized () const;

		string pretty () const;

	public:
    /**
      * Renvoie la produit scalaire des deux vecteurs passés en 
      * paramètre.
      *
      * @param v1 Membre de gauche du produit scalaire.
      * @param v2 Membre de droite du produit scalaire.
      * @return Résultat du produit scalaire.
      */
		static P Dot ( const Vector<P, N>& v1, const Vector<P, N>& v2 );

    /**
      * Renvoie le produit vectoriel de deux vecteur de dimension 3
      *
      * @param v1 Membre de gauche du produit vectoriel.
      * @param v2 Membre de droite du produit vectoriel.
      * @return Résultat du produit vectoriel.
      */
		static Vector<P, 3> Cross 
      ( const Vector<P, 3>& v1, const Vector<P, 3>& v2 );

	public:
		Vector<P, N> operator + ( const Vector<P, N>& v2 ) const;

		Vector<P, N> operator - ( ) const;
		Vector<P, N> operator - ( const Vector<P, N>& v2 ) const;

		P& operator [] ( int i );

		friend ostream &operator << (ostream& oss, const Vector<P, N >& v) {
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

#include "Vector.tcc"
#endif // VECTOR_H_
