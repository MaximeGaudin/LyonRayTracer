/**
  * @file HitRecord.hpp
  * @author Maxime Gaudin
  * @date 2011
  *
  * Ce fichier définit la structure permettant de stocker le résultat 
  * d'un lancer de rayon. Il permet de mémoriser toutes les informations 
  * nécessaires aux différents calcul dans le cas où il y a eu intersection.
  */
#ifndef HIT_RECORD_H_
#define HIT_RECORD_H_
#include <common.hpp>
#include <Vector.hpp>

#include <iostream>

class Geometry;

struct HitRecord {
  /**
    * Indique si le rayon a touché une géométrie.
    */
  bool hit;

  /**
    * Indique à quel endroit du rayon la géométrie à été
    * touchée.
    * @remark Valable si seulement une géométrie à été touchée.
    */
  double t;

  /**
    * Indique la normale à l'endroit de l'intersection.
    * @remark Valable si seulement une géométrie à été touchée.
    */
  Vector3d normal;

  /**
    * Indique l'endroit de l'intersection.
    * @remark Valable si seulement une géométrie à été touchée.
    */
  Vector3d position;

  /**
    * Indique la géométrie touchée.
    * @remark Valable si seulement une géométrie à été touchée.
    */
  Geometry const* hitGeometry;

  friend std::ostream& operator << ( std::ostream& oss, HitRecord const& m) {
    oss << "Hit : " << ( ( m.hit ) ? "Yes" : "No" ) << endl;
    if (m.hit) {
      oss << "t = " << m.t << endl;
      oss << "Position : " << m.position << endl;
      oss << "Normal : " << m.normal << endl; 
    } 

    return oss;
  }
};
#endif
