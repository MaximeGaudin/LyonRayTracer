Ray getReflectedRay ( Ray const& ray, HitRecord const& record ) {
  double d = Vector3d::Dot ( record.normal, -ray.direction() );
  return Ray ( record.position + 0.01 * record.normal, 
      ( 2 * record.normal * d ) + ray.direction() );
}
