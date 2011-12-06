/**
  * @file Geometry.hpp
  * @author Maxime Gaudin.
  * @date 2011
  *
  * Cette classe est l'interface de tous les objets dont on peut calculer
  * l'intersection avec un ray
  */
#ifndef GEOMETRY_H_
#define GEOMETRY_H_
#include <Buildable.hpp>

#include <HitRecord.hpp>
#include <Ray.hpp>
#include <Material.hpp>
#include <Maths.hpp>

class Geometry : public Buildable {
  public:
    Geometry ( );

    /**
      * @param material Matériaux lié à la géométrie
      */
    Geometry ( Material* material );

    /**
      * @param material Matériaux lié à la géométrie.
      * @param translation Translation à appliquer à la géométrie.
      * @param rotation Rotation à appliquer à la géométrie.
      * @param scale Mise à l'échelle à appliquer à la géométrie.
      */ 
    Geometry ( 
        Material* material, 
        Vector3d const& translation,
        Vector3d const& rotation,
        Vector3d const& scale );

  public:
    /**
      * @return L'enregistrement lié à la collision du rayon @a ray et
      * la géométrie.
      *
      * @param ray Rayon à intersecter.
      */
    virtual HitRecord getRecord ( Ray const& ray ) const = 0 ;

    /**
      * @return La coordonnées de texture correspondant à l'intersection
      * enregistrée
      * @param record Enregistrement de l'intersection.
      */
    virtual Vector<double, 2> getUVFromHit ( HitRecord const& record ) const;

  public:
    /**
      * @return Le matériau de la géométrie.
      */
    Material* material() const { return material_; }

  protected:
    Material* material_;

    Vector3d translation_; 
    Vector3d rotation_; 
    Vector3d scale_;
    Matrix<double, 4, 4> transformation_;
};
#endif // GEOMETRY_H_
