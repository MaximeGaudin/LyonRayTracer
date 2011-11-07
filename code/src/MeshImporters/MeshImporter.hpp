#ifndef MESH_IMPORTER_H_
#define MESH_IMPORTER_H_
#include <Mesh.hpp>

class MeshImporter {
  public:
    virtual Mesh build ( string const& filename ) = 0;
};
#endif // MESH_IMPORTER_H_
