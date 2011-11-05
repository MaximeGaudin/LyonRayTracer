#ifndef HIT_RECORD_H_
#define HIT_RECORD_H_

struct HitRecord {
  bool Hit;

  double t;

  Vector < double, 3 > normal;
  Vector < double, 3 > position;

  Geometry* HitGeometry;
};
#endif
