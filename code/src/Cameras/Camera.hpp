/**
  * @file Camera.hpp
  * @author Maxime Gaudin
  * @date 2011
  *
  * Cette classe est l'interface de toutes les caméra et définit l'ensemble des 
  * méthodes à respecter. Pour être compliant, les classes héritées doivent
  * remplir le vecteur de contenant l'ensemble des rayons à lancer.
  * Cet itérateur les stockent en parcourant l'image de gauche à droite, et en 
  * partant du coin supérieur gauche.
  */
#ifndef CAMERA_H_
#define CAMERA_H_
#include <Ray.hpp>

using namespace std;

class Camera {
  public:
    virtual Ray getRay ( double u, double v ) const = 0;
};
#endif // CAMERA_H_
