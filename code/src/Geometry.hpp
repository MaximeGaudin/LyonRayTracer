#ifndef GEOMETRY_H_
#define GEOMETRY_H_
#include <HitRecord.hpp>
#include <Ray.hpp>
#include <Material.hpp>

class Geometry {
  public:
    HitRecord getRecord ( Ray ray ) const;

  public:
    Material& Mat();

  protected:
    Material material_;
};
#endif // GEOMETRY_H_
