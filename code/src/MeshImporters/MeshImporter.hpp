#ifndef MESH_IMPORTER_H_
#define MESH_IMPORTER_H_
#include <string>
#include <Matrix.hpp>

class Mesh; 

class MeshImporter {
  public:
    virtual Mesh* build ( std::string const& filename, 
        Matrix<double,4,4> const& transformation ) = 0;
};
#endif // MESH_IMPORTER_H_
