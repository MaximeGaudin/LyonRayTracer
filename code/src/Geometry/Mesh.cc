#include "Mesh.hpp"

Mesh::Mesh ( vector<Triangle> triangleList ) 
  : Geometry()
    , triangleList_(triangleList)
    , transformation_(Matrix<double,4,4>(IDENTITY))
    , translation_(V3d_Zero)
    , rotation_(V3d_Zero)
{}

HitRecord Mesh::getRecord ( Ray ray ) const {
  HitRecord record;
  record.hit = false;
  record.hitGeometry = this;

  vector<Triangle>::const_iterator it = triangleList_.begin();
  while ( it != triangleList_.end() ) {
    HitRecord currentRecord = it->getRecord ( ray );
    if ( currentRecord.hit ) return currentRecord;
    ++it;
  }

  return record;
} 
