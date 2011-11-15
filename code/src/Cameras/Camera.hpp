/**
  * @file Camera.hpp
  * @author Maxime Gaudin
  * @date 2011
  *
  * Cette classe est l'interface de toutes les caméras.
  * TODO: Parler de la base UV.
  */
#ifndef CAMERA_H_
#define CAMERA_H_
#include <Ray.hpp>

class Camera {
  public:
    virtual Ray getRay ( double u, double v ) const = 0;
};
#endif // CAMERA_H_
