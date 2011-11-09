#ifndef MESH_IMPORTER_3DS_H_
#define MESH_IMPORTER_3DS_H_
#include "MeshImporter.hpp"

#include <Mesh.hpp>

class MeshImporter3ds: public MeshImporter {
  public:
    Mesh* build ( string const& filename );
};
#endif // MESH_IMPORTER_H_
