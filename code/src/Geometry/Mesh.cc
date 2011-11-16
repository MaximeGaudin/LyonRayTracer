#include "Mesh.hpp"
#include "Triangle.hpp"
#include "OctreeNode.hpp"

#include <boost/foreach.hpp>
#define feach BOOST_FOREACH

Mesh::Mesh ( vector<Triangle*> const& triangleList ) : 
  Geometry(),
  triangleList_(triangleList)
{

  setupMesh ();
}

Mesh::~Mesh () {
 feach(Triangle* t, triangleList_) delete t;
 delete octreeRoot_;
}

void Mesh::setupMesh () {
  logInformation ( "Mesh", str ( format("OK (%1$d faces)") 
        % triangleList_.size() ) );

  logInformation("Mesh", "Bounding box computation...");
  Vector3d center; 
  feach ( Triangle* tr, triangleList_)
    center += tr->getBarycenter();
  center /= triangleList_.size();

  double maxDistance = 0.0;
  feach ( Triangle* tr, triangleList_) {
    double currentDistance = (tr->getBarycenter() - center).Length();
    if ( currentDistance > maxDistance ) maxDistance = currentDistance;
  }

  logInformation("Mesh", "Octree computation...");
  octreeRoot_ = new OctreeNode ( 
      Box (center + (1.0 + maxDistance) * (V3d_Down + V3d_Left + V3d_Forward),
      center + (1.0 + maxDistance) * (V3d_Up + V3d_Right + V3d_Backward) ),
      triangleList_, 20 );
}

HitRecord Mesh::getRecord ( Ray const& ray ) const {
  HitRecord record = octreeRoot_->getRecord ( ray );
  record.hitGeometry = this;

  return record;
} 
