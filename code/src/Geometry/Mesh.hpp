#ifndef MESH_H_
#define MESH_H_
#include <common.hpp>
#include <Geometry.hpp>

#include <vector>

#include <Maths.hpp>

class OctreeNode;
class Triangle;

class Mesh: public Geometry {
  public:
    Mesh ( std::vector<Triangle*> const& triangleList );

    Mesh ( 
        std::vector<Triangle*> const& triangleList, 
        Vector3d const& translation, 
        Vector3d const& rotation,
        Vector3d const& scale );

    ~Mesh();

  public:
    HitRecord getRecord ( Ray const& ray ) const;

  private:
    void setupMesh();

  protected:
    std::vector<Triangle*> triangleList_;

  private:
    OctreeNode* octreeRoot_;
};
#endif // MESH_H_
