#ifndef HIT_RECORD_H_
#define HIT_RECORD_H_
#include <Vector.hpp>
#include <iostream>

using namespace std;

class Geometry;

struct HitRecord {
  bool hit;

  double t;

  Vector < double, 3 > normal;
  Vector < double, 3 > position;

  Geometry const * hitGeometry;

  friend ostream& operator << (ostream& oss, HitRecord const& m) {
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
