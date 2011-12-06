/**
  * @file Light.hpp
  * @author Maxime Gaudin
  * @date 2011
  *
  * Interface de toutes les lumières.
  */
#ifndef LIGHT_H_
#define LIGHT_H_
#include <Buildable.hpp>
#include <common.hpp>

#include <vector>

#include <HitRecord.hpp>
#include <Color.hpp>

class Camera;
class Material;
class Geometry;

class Light : public Buildable {
  public:
    Light () {}
    
    /**
      * @param material Matériau à associer à la lumière.
      */
    Light (Material* material) : material_(material) {}

  public:
    /**
      * @return La contribution, c'est à dire l'ajout de lumière de la 
      * source à la lumière totale du point considéré.
      *
      * @param camera La caméra à considérer.
      * @param geometries Listes des géométries de la scène.
      * @param record Enregistrement de l'intersection.
      */
    virtual Color_d getContribution ( 
        Camera* camera, 
        std::vector<Geometry*> const& geometries,
        HitRecord const& record ) const = 0;

  protected:
    Material* material_;
};
#endif // LIGHT_H_
