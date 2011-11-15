/**
  * @file Camera.hpp
  * @author Maxime Gaudin
  * @date 2011
  *
  * Cette classe est l'interface de toutes les caméras.
  * Les coordonnées utilisées dans cette classe (et donc toutes les classes qui
  * en héritent) doivent utiliser le système de coordonnées UV qui est définit
  * comme suit :
  * (0,1)----------(1,1)
  *   |              |
  *   |              |
  *   |              |
  *   |              |
  *   |              |
  * (0,0)----------(1,0)
  */
#ifndef CAMERA_H_
#define CAMERA_H_
#include <vector>
#include <Ray.hpp>

class Camera {
  public:

    /**
      * @return L'ensemble des rayons associés à la coordonnée (u,v)
      */
    virtual std::vector<Ray> getRay ( double u, double v ) const = 0;
};
#endif // CAMERA_H_
