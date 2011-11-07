#include "MeshImporter3ds.hpp"

//#include <lib3ds.h>
#include <lib3ds/file.h>
#include <lib3ds/mesh.h>

#include <Vector.hpp>

#include <exceptions.hpp>

#include <boost/format.hpp>

using namespace std;
using boost::format;
using boost::io::group;

Mesh MeshImporter3ds::build ( string const& filename ) {
  Lib3dsFile* model;
  model = lib3ds_file_load(filename.c_str());
  if ( !model ) logException ("MeshImporter3ds", "Can't open file.");

  logInformation ( "MeshImporter3ds", str ( format("Loading %1%...") % filename ) );

  vector < Triangle > triangleList;
  Lib3dsMesh * mesh;
  for(mesh = model->meshes;mesh != NULL;mesh = mesh->next) {
    for(unsigned int i = 0; i < mesh->faces; ++i) {
      Lib3dsFace * face = &mesh->faceL[i];
      Vector3d A; Vector3d B; Vector3d C;
      
      A[0] = mesh->pointL[face->points[0]].pos[0];
      A[1] = mesh->pointL[face->points[0]].pos[1];
      A[2] = mesh->pointL[face->points[0]].pos[2];

      B[0] = mesh->pointL[face->points[1]].pos[0];
      B[1] = mesh->pointL[face->points[1]].pos[1];
      B[2] = mesh->pointL[face->points[1]].pos[2];

      C[0] = mesh->pointL[face->points[2]].pos[0];
      C[1] = mesh->pointL[face->points[2]].pos[1];
      C[2] = mesh->pointL[face->points[2]].pos[2];

      triangleList.push_back( Triangle (A, B, C ) );
    }
  }

  logInformation ( "MeshImporter3ds", str ( format("OK (%1$d faces)") % triangleList.size() ) );
  lib3ds_file_free( model );

  return Mesh ( triangleList ); 
}
