#ifndef OCTREE_NODE_H_
#define OCTREE_NODE_H_
#include <Box.hpp>
#include <vector>
#include <Geometry.hpp>

using namespace std;

class OctreeNode : public Geometry {
  public:
    OctreeNode ();
    OctreeNode (
      Box const& box,
      vector< Triangle* > const& triangles,
      unsigned int minTriangles);

  public:
    HitRecord getRecord ( Ray const& ray ) const;
    Box getBox () const { return box_; }
    Vector<double, 2> getUVFromHit ( HitRecord const& record ) const { }

  private:
    Box createBox ( Vector3d const& origin ) const;

  protected:
    Box box_;
    bool isLeaf_;
    vector< Triangle* > triangles_;

    vector< OctreeNode* > subNodes_;
};
#endif // OCTREE_NODE_H_
