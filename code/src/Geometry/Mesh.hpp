#ifndef MESH_H_
#define MESH_H_
#include <Maths.hpp>
#include <Triangle.hpp>
#include <Sphere.hpp>
#include <vector>
#include <OctreeNode.hpp>

using namespace std;

class Mesh: public Geometry {
  public:
    Mesh ( vector<Triangle*> triangleList );
    Mesh ( vector<Triangle*> triangleList, 
        Vector3d translation, Vector3d rotation, Vector3d scale );

  public:
    HitRecord getRecord ( Ray ray ) const;

  protected:
    vector<Triangle*> triangleList_;
    OctreeNode octreeRoot_;

    Matrix<double, 4, 4> transformation_;
    Vector3d translation_; 
    Vector3d rotation_; 
    Vector3d scale_;

    Sphere boundingSphere_;
};
#endif // MESH_H_