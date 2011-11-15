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
    * Indique à quelle endroit du rayon la géométrie à été
    * touchée.
    * @remark Valable si seulement une géométrie à été touchée.
    */
  double t;

  /**
    * Indique la normal à l'endroit de l'intersection.
    * @remark Valable si seulement une géométrie à été touchée.
    */
  Vector3d normal;

  /**
    * Indique l'endroit de l'intersection.
    * @remark Valable si seulement une géométrie à été touchée.
    */
  Vector3d position;

  /**
    * Indique l'endroit de l'intersection.
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
