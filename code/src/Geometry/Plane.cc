#include <Plane.hpp>
#include <cmath>
#include <iostream>
using namespace std;

Plane::Plane ( Vector3d const& point, Vector3d const& normal ) :
  Geometry(),
  point_(point),
  normal_(normal.Normalized())
{
  setupUV();
}

Plane::Plane ( Vector3d const& point, Vector3d const& normal, Material* material ) :
  Geometry(material),
  point_(point),
  normal_(normal.Normalized())
{ 
  setupUV();
}

void Plane::setupUV () {
  U_[0] = normal_[1]; 
  U_[1] = normal_[2]; 
  U_[2] = -normal_[0]; 

  V_ = Vector3d::Cross ( U_, normal_ ).Normalized();
}

HitRecord Plane::getRecord ( Ray const& ray ) const {
  HitRecord record;
  record.hit = false;
  record.hitGeometry = this;

  double d = Vector3d::Dot ( ray.direction(), normal_ );

  if ( d != 0.0 ) {
    double t = -1.0 * ( Vector3d::Dot ( normal_, ray.from() ) + point_.Length() ) / d;
    if ( t >= 0 ) {
      record.hit = true;
      record.t = t;
      record.position = ray.from() + t * ray.direction();
      record.normal = normal_;
    }
  }

  return record;
}


Vector<double, 2> Plane::getUVFromHit ( HitRecord const& record ) const {
 Vector<double, 2> UV;

 UV[0] = fmod ( Vector3d::Dot ( record.position, U_ ) * material_->UVScale, 1.0 );
 UV[1] = fmod ( Vector3d::Dot ( record.position, V_ ) * material_->UVScale, 1.0);

 // A optimiser ... 
 while ( UV[0] < 0.0 ) UV[0] += 1.0;
 while ( UV[1] < 0.0 ) UV[1] += 1.0;

 return UV;
}
