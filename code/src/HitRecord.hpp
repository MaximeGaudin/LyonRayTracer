#ifndef HIT_RECORD_H_
#define HIT_RECORD_H_
#include <Vector.hpp>

class Geometry;

struct HitRecord {
  bool hit;

  double t;

  Vector < double, 3 > normal;
  Vector < double, 3 > position;

  Geometry const * hitGeometry;
};
#endif
