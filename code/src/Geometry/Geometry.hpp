#ifndef GEOMETRY_H_
#define GEOMETRY_H_
#include <HitRecord.hpp>
#include <Ray.hpp>
#include <Material.hpp>

class Geometry {
  public:
    Geometry ( ) {}

    /**
      * @param material Matériaux lié à la géométrie
      */
    Geometry ( Material material ) : material_( material ) {}

  public:

    /**
      * @return L'enregistrement lié à la collision du rayon @a ray et
      * la géométrie.
      * @param ray Rayon à intersecter.
      */
    virtual HitRecord getRecord ( Ray ray ) const = 0 ;

  public:
    /**
      * @return Le matériaux de la géométrie.
      */
    Material material() const { return material_; }

  protected:
    Material material_;
};
#endif // GEOMETRY_H_
