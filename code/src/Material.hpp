#ifndef MATERIAL_H_
#define MATERIAL_H_
#include <Color.hpp>

class Material {
  public:
    Material ( );

    /*
     * @param diffuse Couleur diffuse du matériaux.
     */
    Material ( Color<double> diffuse );

    /*
     * @param diffuse Couleur diffuse du matériaux.
     * @param diffuse Couleur diffuse du ambient.
     * @param diffuse Couleur diffuse du specular.
     */
    Material ( Color<double> diffuse, Color<double> ambient, Color<double> specular );

  public:
    /*
     * Couleur ambiente du matériaux, i.e. la couleur que possède la matériaux
     * sans aucun éclairage. Elle est ajouté à toutes les autres couleurs
     */
    Color<double> ambient;

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
    Color<double> diffuse;
    
    /**
      * Intensité de la couleur diffuse, 
      * i.e. le coefficient multiplicateur de la couleur diffuse.
      */
    double diffuseIntensity;

    /// Couleur spéculaire du matériaux.
    Color<double> specular;

    /// Puissance de spécularitée.
    double specularPower;
};
#endif // MATERIAL_H_
