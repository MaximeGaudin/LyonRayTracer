#include "Triangle.hpp"
#include <Plane.hpp>

bool isCCW ( Vector3d a, Vector3d b, Vector3d c, Vector3d normal ) {
  Vector3d u = b - a;
  Vector3d v = c - a;

  return Vector3d::Cross ( u, v ) == normal;
}

  Triangle::Triangle ( Vector3d a, Vector3d b, Vector3d c )
  : Geometry () 
  , a_(a)
  , b_(b)
    , c_(c)
{ aNormal_ = bNormal_ = cNormal_ = Vector3d::Cross ( b - a, c - a ).Normalized(); }

  Triangle::Triangle ( Vector3d a, Vector3d b, Vector3d c, Material material )
  : Geometry (material) 
  , a_(a)
  , b_(b)
    , c_(c)
{
  aNormal_ = bNormal_ = cNormal_ = Vector3d::Cross ( b - a, c - a ).Normalized();
}

  Triangle::Triangle ( Vector3d a, Vector3d b, Vector3d c, Vector3d normal )
  : Geometry () 
  , a_(a)
  , b_(b)
    , c_(c)
{
  cout << a_ << b_ << c_ << normal << endl;
  aNormal_ = bNormal_ = cNormal_ = normal; 
}

  Triangle::Triangle ( Vector3d a, Vector3d b, Vector3d c, Vector3d normal, Material material )
  : Geometry (material) 
  , a_(a)
  , b_(b)
    , c_(c)
{
  if ( !isCCW (a, b, c, normal) ) {
    b_ = c;
    c_ = b;
  }

  aNormal_ = bNormal_ = cNormal_ = normal; 
}


// Getters 
Vector3d Triangle::getBarycenter () const {
  return (a_ + b_ + c_ ) / 3.0;
}

HitRecord Triangle::getRecord ( Ray ray ) const {
  HitRecord record;
  record.hit = false;
  record.hitGeometry = this;

  Vector3d u = b_ - a_;
  Vector3d v = c_ - a_;

  double d = -1.0 * (Vector3d::Dot ( Vector3d::Cross(u,v), ray.direction() ));
  Vector3d w = ray.from() - a_;

  float a = -1.0 * Vector3d::Dot( Vector3d::Cross(w, v), ray.direction() ) /d;
  float b = -1.0 * Vector3d::Dot( Vector3d::Cross(u, w), ray.direction() ) /d;

  double t = Vector3d::Dot ( Vector3d::Cross (u, v), w ) / d;

  if ( a == -0 ) a = 0;
  if ( b == -0 ) b = 0;

  if (a > 0 && b > 0 && a + b <= 1 && t > 0.0)
  {
    record.t = t;
    record.hit = true;
    record.normal = aNormal_;
    record.position = ray.from() + record.t * ray.direction();
  }

  return record;
} 

/*
   HitRecord Triangle::getRecord ( Ray ray ) const {
   HitRecord record;
   record.hit = false;
   record.hitGeometry = this;

   HitRecord planeRecord = Plane ( a_, aNormal_ ).getRecord ( ray );
   if ( !planeRecord.hit ) return record;
   if ( planeRecord.t < 0 ) return record;

   Vector3d v0 = c_ - a_;
   Vector3d v1 = b_ - a_;
   Vector3d v2 = planeRecord.position - a_;

   double d00 = Vector3d::Dot(v0, v0);
   double d01 = Vector3d::Dot(v0, v1);
   double d02 = Vector3d::Dot(v0, v2);
   double d11 = Vector3d::Dot(v1, v1);
   double d12 = Vector3d::Dot(v1, v2);

   double invDenom = 1 / (d00 * d11 - d01 * d01);
   double u = (d11 * d02 - d01 * d12) * invDenom;
   double v = (d00 * d12 - d01 * d02) * invDenom;

   if ( ! ((u >= 0) && (v >= 0) && (u + v < 1)) ) return record;

   record.hit = true;
   record.t = planeRecord.t;
   record.normal = aNormal_;
   record.position = planeRecord.position;
//  cout << record.position << endl;

return record;
} 

HitRecord Triangle::getRecord ( Ray ray ) const {
HitRecord record;
record.hit = false;
record.hitGeometry = this;

HitRecord planeRecord = Plane ( a_, normal_ ).getRecord ( ray );
if ( !planeRecord.hit ) return record;
if ( planeRecord.t < 0 ) return record;

Vector3d u = b_ - a_;
Vector3d v = c_ - b_;
Vector3d w = a_ - c_;
Vector3d x = ray.from() + planeRecord.t * ray.direction();

if (
Vector3d::Dot ( Vector3d::Cross ( u, x - a_ ), normal_ ) >= 0 
&& Vector3d::Dot ( Vector3d::Cross ( v, x - b_ ), normal_ ) >= 0 
&& Vector3d::Dot ( Vector3d::Cross ( w, x - c_ ), normal_ ) >= 0 )
{
planeRecord.hitGeometry = this;
return planeRecord;
}

return record;
}
*/
