#ifndef RAY_H_
#define RAY_H_
#include <Vector.hpp>

class Ray {
  public: // Ctor & Dtor
    Ray ( Vector3d from, Vector3d to );
    Ray ( Vector3d from, Vector3d direction, bool Normalize );

  public:
    string pretty() const; 

    friend ostream& operator << (ostream& oss, const Ray& r ) {
      oss << r.pretty();
      return oss;
    }

  public: // Getters & Setters
    Vector3d from() const;
    Vector3d to() const;
    Vector3d direction() const;

  private: 
    Vector3d from_;
    Vector3d to_;
    Vector3d direction_;
};
#endif
