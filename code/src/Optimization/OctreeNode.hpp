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
      Box box,
      vector< Triangle* > triangles,
      unsigned int minTriangles);

  public:
    HitRecord getRecord ( Ray ray ) const;
    Box getBox () const { return box_; }

  private:
    Box createBox ( Vector3d origin ) const;

  protected:
    Box box_;
    bool isLeaf_;
    vector< Triangle* > triangles_;

    vector< OctreeNode* > subNodes_;
};
#endif // OCTREE_NODE_H_
