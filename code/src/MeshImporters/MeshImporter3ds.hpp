#ifndef MESH_IMPORTER_3DS_H_
#define MESH_IMPORTER_3DS_H_
#include "MeshImporter.hpp"

class MeshImporter3ds: public MeshImporter {
  public:
    virtual Mesh* build ( std::string const& filename, 
        Matrix<double,4,4> const& transformation ) = 0;
};
#endif // MESH_IMPORTER_H_
