/**
  * @file MaterialBuilder.hpp
  * @author Maxime Gaudin
  * @date 2011
  *
  * Builder associé à l'objet Material.
  */
#ifndef MATERIAL_BUILDER_H_
#define MATERIAL_BUILDER_H_
#include <Builder.hpp>

#include <string>
#include <boost/property_tree/ptree.hpp>

class Buildable;

class MaterialBuilder : public Builder {
  public:
    MaterialBuilder ();

  public:
    Buildable* getObject( 
        boost::property_tree::ptree pt,
        Material* material ) const;
};
#endif // MATERIAL_BUILDER_H_
