#include "MeshImporter3ds.hpp"

//#include <lib3ds.h>
#include <lib3ds/file.h>
#include <lib3ds/mesh.h>

#include <Vector.hpp>

#include <exceptions.hpp>

Mesh* MeshImporter3ds::build ( string const& filename ) {
  Lib3dsFile* model;
  model = lib3ds_file_load(filename.c_str());
  if ( !model ) logException ("MeshImporter3ds", "Can't open file.");

  logInformation ( "MeshImporter3ds", str ( format("Loading %1%...") % filename ) );

  vector < Triangle* > triangleList;
  Lib3dsMesh* mesh;
  for(mesh = model->meshes;mesh != NULL;mesh = mesh->next) {
    Lib3dsVector* normals = new Lib3dsVector[3 * sizeof(Lib3dsVector) * mesh->faces];
    lib3ds_mesh_calculate_normals ( mesh, normals );

    for(unsigned int i = 0; i < mesh->faces; ++i) {
      Lib3dsFace * face = &mesh->faceL[i];
      Vector3d A; Vector3d B; Vector3d C; 
      Vector3d NA; Vector3d NB; Vector3d NC;
      
      A[0] = mesh->pointL[face->points[0]].pos[0];
      A[1] = mesh->pointL[face->points[0]].pos[1];
      A[2] = mesh->pointL[face->points[0]].pos[2];
      NA[0] = normals[3*i + 0][0];
      NA[1] = normals[3*i + 0][1];
      NA[2] = normals[3*i + 0][2];

      B[0] = mesh->pointL[face->points[1]].pos[0];
      B[1] = mesh->pointL[face->points[1]].pos[1];
      B[2] = mesh->pointL[face->points[1]].pos[2];
      NB[0] = normals[3*i + 1][0];
      NB[1] = normals[3*i + 1][1];
      NB[2] = normals[3*i + 1][2];

      C[0] = mesh->pointL[face->points[2]].pos[0];
      C[1] = mesh->pointL[face->points[2]].pos[1];
      C[2] = mesh->pointL[face->points[2]].pos[2];
      NC[0] = normals[3*i + 2][0];
      NC[1] = normals[3*i + 2][1];
      NC[2] = normals[3*i + 2][2];


      triangleList.push_back( new Triangle (A, B, C, NA, NB, NC) );
    }

    delete[] normals;
  }

  logInformation ( "MeshImporter3ds", str ( format("OK (%1$d faces)") % triangleList.size() ) );
  lib3ds_file_free( model );

  return new Mesh ( triangleList ); 
}
