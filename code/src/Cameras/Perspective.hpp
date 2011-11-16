#ifndef PERSPECTIVE_H_
#define PERSPECTIVE_H_
#include <vector>

#include <common.hpp>

#include <Camera.hpp>
#include <PerspectiveBuilder.hpp>

#include <Vector.hpp>
#include <Ray.hpp>

class Perspective : public Camera {
  public:
    /**
     * @param eye Position de la caméra.
     * @param lookTo Endroit où la caméra pointe.
     * @param up Vecteur indiquant où doit pointer le haut de l'image.
     *
     * @remark Par défaut, la distance focale de la caméra est 1.0.
     */
    Perspective ( 
        Vector3d const& eye,
        Vector3d const& lookAt,
        Vector3d const& up );

    /**
     * @param focaleDistance Distance focale de la caméra.
     * @param eye Position de la caméra.
     * @param lookTo Endroit où la caméra pointe.
     * @param up Vecteur indiquant où doit pointer le haut de l'image.
     */
    Perspective ( 
        double focaleDistance,
        Vector3d const& eye,
        Vector3d const& lookAt,
        Vector3d const& up );

  public:
    std::vector<Ray> getRay ( double u, double v ) const;

  private:
    void setupCameraBase ( );

  protected:
    double focaleDistance_;
    Vector3d eye_;
    Vector3d lookAt_;
    Vector3d up_;

  private:
    Vector3d IPNormal_;
    Vector3d IPXAxis_;
    Vector3d IPYAxis_;
    Vector3d IPZAxis_;
    double fov_;
};
#endif // PERSPECTIVE_H_
