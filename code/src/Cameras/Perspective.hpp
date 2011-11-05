#ifndef PERSPECTIVE_H_
#define PERSPECTIVE_H_
#include <Camera.hpp>

#include <Vector.hpp>

class Perspective : public Camera {
  public:
    /**
      * @param eye Position de la caméra.
      * @param lookTo Endroit où la caméra pointe.
      * @param up Vecteur indiquant où doit pointer le haut de l'image.
      */
    Perspective ( 
        unsigned int resX, unsigned int resY,
        Vector < double, 3 > eye,
        Vector < double, 3 > lookTo,
        Vector < double, 3 > up );

  private:
    void initialize (  
        Vector < double, 3 > eye,
        Vector < double, 3 > direction,
        Vector < double, 3 > up );
};
#endif // PERSPECTIVE_H_