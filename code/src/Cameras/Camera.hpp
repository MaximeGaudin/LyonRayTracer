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
#include <vector>

using namespace std;

class Camera {
  public:
    /**
      * @param resX Nombre de pixel à remplir sur l'axe horizontal de l'image 
      * finale.
      * @param resY Nombre de pixel à remplir sur l'axe vertical de l'image 
      * finale.
      */
    Camera ( unsigned int resX, unsigned int resY ) : resX_(resX), resY_(resY) {}

    vector<Ray>::const_iterator begin() { return rayCollection_.begin(); }
    vector<Ray>::const_iterator end() { return rayCollection_.end(); }

  protected:
      /** 
        * resX Nombre de pixel à remplir sur l'axe horizontal de l'image 
        * finale.
        */
    unsigned int resX_;

      /** 
        * resX Nombre de pixel à remplir sur l'axe horizontal de l'image 
        * finale.
        */
    unsigned int resY_;

    /**
      * Collection des rayons à lancer pour calculer l'image.
      */
    vector <Ray> rayCollection_;
};
#endif // CAMERA_H_
