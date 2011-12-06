#include "Mesh.hpp"

#include <Triangle.hpp>
#include <OctreeNode.hpp>

#include <boost/foreach.hpp>

Mesh::Mesh ( 
        std::vector<Triangle*> const& triangleList, 
        Material* material,
        Vector3d const& translation, 
        Vector3d const& rotation,
        Vector3d const& scale ) :
  Geometry( material, translation, rotation, scale ),
  triangleList_ ( triangleList )
{
  setupMesh ();
}

Mesh::~Mesh () {
 feach(Triangle* t, triangleList_) delete t;
 delete octreeRoot_;
}

void Mesh::setupMesh () {
  // TODO Transformation des triangles

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
      triangleList_, 25 );
}

HitRecord Mesh::getRecord ( Ray const& ray ) const {
  HitRecord record = octreeRoot_->getRecord ( ray );
  record.hitGeometry = this;

  return record;
} 
