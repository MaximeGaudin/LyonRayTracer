/**
  * @file AreaBuilder.hpp
  * @author Maxime Gaudin
  * @date 2011
  *
  * Builder associé à l'objet AreaLight.
  */
#ifndef AREA_BUILDER_H_
#define AREA_BUILDER_H_
#include <Builder.hpp>

#include <string>
#include <boost/property_tree/ptree.hpp>

class Buildable;

class AreaBuilder : public Builder {
  public:
    AreaBuilder ();

  public:
    Buildable* getObject( 
        boost::property_tree::ptree pt,
        Material* material ) const;
};
#endif // AREA_BUILDER_H_
