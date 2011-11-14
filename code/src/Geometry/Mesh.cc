#include "Mesh.hpp"

#include <boost/foreach.hpp>
#define feach BOOST_FOREACH

Mesh::Mesh ( vector<Triangle> triangleList ) 
  : Geometry()
    , triangleList_(triangleList)
    , transformation_(Matrix<double,4,4>(IDENTITY))
    , translation_(V3d_Zero)
    , rotation_(V3d_Zero)
    , boundingSphere_( V3d_Zero, 0.0 )
{
  Vector3d center; 

  feach ( Triangle tr, triangleList) { 
    center += tr.getBarycenter();
  }
  center /= triangleList.size();

  double maxDistance = 0.0;
  feach ( Triangle tr, triangleList_) {
    double currentDistance = (tr.getBarycenter() - center).Length();
    if ( currentDistance > maxDistance ) maxDistance = currentDistance;
  }

  boundingSphere_ = Sphere ( center, maxDistance );
  cout << center << " - " << maxDistance << endl;
}

HitRecord Mesh::getRecord ( Ray ray ) const {
  HitRecord closestHit;
  closestHit.hit = false;
  double closestT = numeric_limits<double>::infinity();

  feach ( Triangle tr, triangleList_) {
    HitRecord newRecord = tr.getRecord ( ray );

    if ( newRecord.hit && newRecord.t < closestT ) {
      closestT = newRecord.t;
      closestHit = newRecord;
    }
  }

  closestHit.hitGeometry = this;
  return closestHit;
} 
