#ifndef COLOR_H_
#define COLOR_H_

#include <iostream>
#include <string>

using namespace std;

template < typename P >
class Color {
  public: // Ctors 
    Color ( P const& v );
    Color ( P const& R, P const& G, P const &B );
    Color ( Color<P> const& C );

  public:
    string pretty () const;

  public:
    Color<P> operator + ( Color <P> const& C2 ) const;
    Color<P> operator + ( P const& C2 ) const;
   
    Color<P> operator - ( Color <P> const& C2 ) const;
    Color<P> operator - ( P const& C2 ) const;

    Color<P> operator * ( Color <P> const& C2 ) const;
    Color<P> operator * ( P const& C2 ) const;

    friend ostream& operator << (ostream& oss, Color<P> const& c) const {
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

#endif // COLOR_H_
