#ifndef VECTOR_H
#define VECTOR_H
#include <string>
#include <ostream>
#include <boost/type_traits.hpp>

using namespace std;

template <typename P, int N >
class Vector {
	public:
		Vector ();
		Vector (P v);
		Vector (const Vector<P, N>& v);

	public:
		P Length () const;
		P SquaredLength () const;

		Vector<P, N> Normalized () const;

		string pretty () const;

	public:
		static P Dot ( const Vector<P, N>& v1, const Vector<P, N>& v2 );
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
		P X() const;
		P Y() const;
		P Z() const;
		P T() const;

	private:
		void checkType () const;

	protected:
		P _values [N];
};
#endif
