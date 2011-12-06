/**
* @file MeshBuilder.hpp
* @author Maxime Gaudin
* @date 2011
*
* Builder associé à l'objet Mesh.
*/
#ifndef MESH_BUILDER_H_
#define MESH_BUILDER_H_
#include <Builder.hpp>

#include <string>
#include <boost/property_tree/ptree.hpp>

class Buildable;

class MeshBuilder : public Builder {
  public:
    MeshBuilder ();

  public:
    Buildable* getObject( 
        boost::property_tree::ptree pt,
        Material* material ) const;
};
#endif // MESH_BUILDER_H_
