#ifndef RAY_H_
#define RAY_H_
#include <Vector.cc>

template <typename P, int N >
class Ray {
  public: // Ctor & Dtor
    Ray ( Vector<P, N> from, Vector<P, N> to );
    Ray ( Vector<P, N> from, Vector<P, N> direction, bool Normalize );

  public:
    string pretty() const; 

    friend ostream& operator << (ostream& oss, const Ray<P, N>& r ) {
      oss << r.pretty();
      return oss;
    }

  public: // Getters & Setters
    Vector<P, N> from() const;
    Vector<P, N> to() const;
    Vector<P, N> direction() const;

  private: 
    Vector<P, N> from_;
    Vector<P, N> to_;
};
#endif
