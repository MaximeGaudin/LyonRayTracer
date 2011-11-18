#ifndef MESH_H_
#define MESH_H_
#include <Geometry.hpp>
#include <common.hpp>

#include <vector>

#include <MeshBuilder.hpp>
#include <Vector.hpp>

class OctreeNode;
class Triangle;
class Material;

class Mesh: public Geometry {
  public:
    Mesh ( 
        std::vector<Triangle*> const& triangleList, 
        Material* material,
        Vector3d const& translation, 
        Vector3d const& rotation,
        Vector3d const& scale );

    ~Mesh();

  public:
    HitRecord getRecord ( Ray const& ray ) const;

    Vector<double, 2> getUVFromHit ( HitRecord const& record ) const { }

  private:
    void setupMesh();

  protected:
    std::vector<Triangle*> triangleList_;

  private:
    OctreeNode* octreeRoot_;
};
#endif // MESH_H_
