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

Triangle::Triangle ( 
    Vector3d a, Vector3d b, Vector3d c, 
    Vector3d aNormal, Vector3d bNormal, Vector3d cNormal 
    ) 
  : Geometry()
  , a_(a)
  , b_(b)
  , c_(c)
  , barycentre_( (a + b + c) / 3.0 )
  , aNormal_(aNormal)
  , bNormal_(bNormal)
    , cNormal_(cNormal)
{ }

// Getters 
Vector3d Triangle::getBarycenter () const {
  return (a_ + b_ + c_ ) / 3.0;
}

Vector3d Triangle::getA () const { return a_; }
Vector3d Triangle::getB () const { return b_; }
Vector3d Triangle::getC () const { return c_; }

// Worker methods
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
    //record.normal = ((1.0 - a + b) * bNormal_ + a * aNormal_ + b * cNormal_).Normalized();
    record.normal = (aNormal_ + a * (bNormal_ - aNormal_) + b * (cNormal_ - aNormal_)).Normalized();
    record.position = ray.from() + record.t * ray.direction();
  }

  return record;
} 
