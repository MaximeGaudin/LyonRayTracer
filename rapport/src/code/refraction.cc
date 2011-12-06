Ray getRefractedRay ( 
    Ray const& ray, 
    double IOR, 
    HitRecord const& record ) 
{
  double n1 = IOR;
  double n2 = record.hitGeometry->material()->IOR;
  double n = n1 / n2;

  double d = Vector3d::Dot ( record.normal, -ray.direction() );
  double c = sqrt( 1 - n * n * (1 - d * d) );

  double thetaMax = asin ( n2 / n1 );
  if ( acos(d) > thetaMax ) 
    return getReflectedRay ( ray, record );

  bool input = ( d < M_PI / 2.0 );

  Vector3d bias = ( input ) 
    ?  -0.01 * record.normal 
    : 0.01 * record.normal;

  Ray newRay ( record.position + bias
      , ( n * ray.direction() ) + ( n * d - c ) * record.normal );

  return newRay;
}
