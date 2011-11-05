#ifndef GEOMETRY_H_
#define GEOMETRY_H_
#include <HitRecord.hpp>
#include <Ray.hpp>
#include <Material.hpp>

class Geometry {
  public:
    Geometry ( ) {}
    Geometry ( Material material ) : material_( material ) {}

  public:
    virtual HitRecord getRecord ( Ray ray ) const = 0 ;

  public:
    Material& Mat();

  protected:
    Material material_;
};
#endif // GEOMETRY_H_
