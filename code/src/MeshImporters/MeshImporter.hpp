#ifndef MESH_IMPORTER_H_
#define MESH_IMPORTER_H_
#include <string>
#include <Matrix.hpp>

class Mesh; 
class Material;

class MeshImporter {
  public:
    virtual Mesh* build ( std::string const& filename, 
        Material* material,
        Vector3d const& translation, 
        Vector3d const& rotation,
        Vector3d const& scale ) const = 0;
};
#endif // MESH_IMPORTER_H_
