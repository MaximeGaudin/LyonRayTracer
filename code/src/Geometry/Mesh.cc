#include "Mesh.hpp"

#include <boost/foreach.hpp>
#define feach BOOST_FOREACH


Mesh::Mesh ( vector<Triangle*> triangleList ) 
  : Geometry()
    , triangleList_(triangleList)
    , transformation_(Matrix<double,4,4>(IDENTITY))
    , translation_(V3d_Zero)
    , rotation_(V3d_Zero)
    , boundingSphere_( V3d_Zero, 0.0 )
{
  logInformation("Mesh", "Bounding sphere computation...");

  Vector3d center; 
  feach ( Triangle* tr, triangleList) { 
    center += tr->getBarycenter();
  }
  center /= triangleList.size();

  double maxDistance = 0.0;
  feach ( Triangle* tr, triangleList_) {
    double currentDistance = (tr->getBarycenter() - center).Length();
    if ( currentDistance > maxDistance ) maxDistance = currentDistance;
  }

  boundingSphere_ = Sphere ( center, maxDistance );

  logInformation("Mesh", "Octree computation...");
  octreeRoot_ = OctreeNode ( 
      Box (center + (1.0 + maxDistance) * (V3d_Down + V3d_Left + V3d_Forward),
      center + (1.0 + maxDistance) * (V3d_Up + V3d_Right + V3d_Backward) ),
      triangleList_, 20 );
}

HitRecord Mesh::getRecord ( Ray ray ) const {
  HitRecord record = octreeRoot_.getRecord ( ray );
  record.hitGeometry = this;

  return record;
} 
