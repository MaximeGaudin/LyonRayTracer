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
        Vector3d eye,
        Vector3d lookAt,
        Vector3d up );

    /**
     * @param focaleDistance Distance focale de la caméra.
     * @param eye Position de la caméra.
     * @param lookTo Endroit où la caméra pointe.
     * @param up Vecteur indiquant où doit pointer le haut de l'image.
     */
    Perspective ( 
        double focaleDistance,
        Vector3d eye,
        Vector3d lookAt,
        Vector3d up );

  public:
    Ray getRay ( double u, double v ) const;

  private:
    void setupCameraBase ( );

  private:
    double focaleDistance_;
    Vector3d eye_;
    Vector3d lookAt_;
    Vector3d up_;

    Vector3d IPNormal_;
    Vector3d IPXAxis_;
    Vector3d IPYAxis_;
    Vector3d IPZAxis_;
    double fov_;

};
#endif // PERSPECTIVE_H_
