#ifndef MESH_IMPORTER_3DS_H_
#define MESH_IMPORTER_3DS_H_
#include "MeshImporter.hpp"

class MeshImporter3ds: public MeshImporter {
  public:
    Mesh* build ( std::string const& filename, 
        Material* material,
        Vector3d const& translation, 
        Vector3d const& rotation,
        Vector3d const& scale ) const;
};
#endif // MESH_IMPORTER_H_
