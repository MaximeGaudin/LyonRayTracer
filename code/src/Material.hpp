/**
  * @file Material.hpp / Material.cc
  * @author Maxime Gaudin.
  * @date 2011
  * 
  * Material définit une classe permettant de stocker les paramètres esthétiques
  * chaque objet comme sa couleur, son opacité, son indice de réfraction, etc.
  *
  * Les paramètres par défault sont :
  * - ambient ( 0.03, 0.03, 0.03 )
  * - opacity ( 1.0 )
  * - IOR ( 1.0 )
  * - Reflexivity ( 0.1 )
  * - Diffuse ( 0.5, 0.5, 0.5 )
  * - Diffuse Intensity ( 1.0 )
  * - Specular ( 1.0, 1.0, 1.0 )
  * - SpecularPower ( 60 )
  */
#ifndef MATERIAL_H_
#define MATERIAL_H_
#include <Buildable.hpp>
#include <MaterialBuilder.hpp>

#include <common.hpp>
#include <Color.hpp>

class Image;

class Material : public Buildable {
  public:
    Material ( );

    /*
     * @param diffuse Couleur diffuse du matériaux.
     */
    Material ( Color_d diffuse );

    /*
     * @param diffuse Couleur diffuse du matériaux.
     * @param diffuse Couleur ambiente du matériaux.
     * @param diffuse Couleur spéculaire du matériaux.
     */
    Material ( Color_d diffuse, Color_d ambient, Color_d specular );

  public:
    /*
     * Couleur ambiente du matériaux, i.e. la couleur que possède la matériaux
     * sans aucun éclairage. Elle est ajouté à toutes les autres couleurs.
     */
    Color_d ambient;

    /*
     * Facteur de transparence :
     * - 1.0 : Totalement opaque
     * - 0.0 : Totalement transparent
     */
    double opacity;

    /// Indice de réfraction du matériaux.
    double IOR;

    /// Reflexivité du matériaux.
    double reflexivity;

    /// Couleur diffuse du matériaux.
    Color_d diffuse;
    
    /**
      * Intensité de la couleur diffuse, 
      * i.e. le coefficient multiplicateur de la couleur diffuse.
      */
    double diffuseIntensity;

    /// Couleur spéculaire du matériaux.
    Color_d specular;

    /// Puissance de spécularitée.
    double specularPower;

    bool hasTexture;
    Image* texture;
};
#endif // MATERIAL_H_
