/**
  * @file Ray.hpp / Ray.cc
  * @author Maxime Gaudin.
  * @date 2011
  */
#ifndef RAY_H_
#define RAY_H_
#include <common.hpp>
#include <Vector.hpp>

#include <iostream>

class Ray {
  public: // Ctor & Dtor
    /**
      * @param from Point de départ du rayon.
      * @param direction Direction que suivra le rayon lumineux.
      * 
      * @remark Le paramètre direction sera automatiquement normalisé.
      */
    Ray ( Vector3d const& from, Vector3d const& direction );

  public:
    string pretty() const; 
    friend std::ostream& operator << ( std::ostream& oss, const Ray& r ) {
      oss << r.pretty();
      return oss;
    }

  public: // Getters & Setters
    /**
      * @return Le point de départ du rayon
      */
    Vector3d from() const;

    /**
      * @return La direction normalisée du rayon.
      */
    Vector3d direction() const;

  private: 
    Vector3d from_;
    Vector3d direction_;
};
#endif
