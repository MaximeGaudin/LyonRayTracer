/**
  * @file Perspective.hpp
  * @author Maxime Gaudin
  * @date 2011
  *
  * Déclare la caméra Perspective. C'est une caméra "normale" avec 
  * projection perspective et effet de profondeur de champ. Le réglage
  * de celui-ci n'est pas trivial et il faut tester plusieurs ouvertures avant
  * d'obtenir un effet réaliste.
  */
#ifndef PERSPECTIVE_DOF_H_
#define PERSPECTIVE_DOF_H_
#include <vector>
#include <PerspectiveDOFBuilder.hpp>
#include <Plane.hpp>

#include <common.hpp>

#include <Camera.hpp>

#include <Vector.hpp>
#include <Ray.hpp>

class PerspectiveDOF : public Camera {
  public:
    /**
     * @param eye Position de la caméra.
     * @param lookAt Endroit où la caméra pointe.
     * @param up Vecteur indiquant où doit pointer le haut de l'image.
     * @param focusPoint Point net.
     * @param sampling Échantillonnage de l'effet.
     * @param aperture "Ouverture" de l'objectif (correspond à la 
     * disturbance appliquée aux rayons.)
     *
     * @remark Par défaut, la distance focale de la caméra est 1.0.
     */
    PerspectiveDOF ( 
        Vector3d const& eye,
        Vector3d const& lookAt,
        Vector3d const& up,
        Vector3d const& focusPoint,
        unsigned int sampling,
        double aperture );

    /**
     * @param focaleDistance Distance focale de la caméra.
     * @param eye Position de la caméra.
     * @param lookAt Endroit où la caméra pointe.
     * @param up Vecteur indiquant où doit pointer le haut de l'image.
     * @param focusPoint Point net.
     * @param sampling Échantillonnage de l'effet.
     * @param focusPoint Point net.
     * @param sampling Échantillonnage de l'effet.
     * @param aperture "Ouverture" de l'objectif (correspond à la 
     * disturbance appliquée aux rayons.)
     * @param aperture "Ouverture" de l'objectif (correspond à la 
     * disturbance appliquée aux rayons.)
     */
    PerspectiveDOF ( 
        double focaleDistance,
        Vector3d const& eye,
        Vector3d const& lookAt,
        Vector3d const& up,
        Vector3d const& focusPoint,
        unsigned int sampling,
        double aperture );


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

    Vector3d focusPoint_;
    unsigned int sampling_;
    double aperture_;

    Plane focusPlane_;
};
#endif // PERSPECTIVE_DOF_H_
