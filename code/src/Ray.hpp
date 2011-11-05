#ifndef RAY_H_
#define RAY_H_
#include <Vector.hpp>

class Ray {
  public: // Ctor & Dtor
    Ray ( Vector<double, 3> from, Vector<double, 3> to );
    Ray ( Vector<double, 3> from, Vector<double, 3> direction, bool Normalize );

  public:
    string pretty() const; 

    friend ostream& operator << (ostream& oss, const Ray& r ) {
      oss << r.pretty();
      return oss;
    }

  public: // Getters & Setters
    Vector<double, 3> from() const;
    Vector<double, 3> to() const;
    Vector<double, 3> direction() const;

  private: 
    Vector<double, 3> from_;
    Vector<double, 3> to_;
};
#endif
