/**
  * @file SphereBuilder.hpp
  * @author Maxime Gaudin
  * @date 2011
  *
  * Builder associé à l'objet Sphere.
  */
#ifndef SPHERE_BUILDER_H_
#define SPHERE_BUILDER_H_
#include <Builder.hpp>

#include <string>
#include <boost/property_tree/ptree.hpp>

class Buildable;

class SphereBuilder : public Builder {
  public:
    SphereBuilder ();

  public:
    Buildable* getObject( 
        boost::property_tree::ptree pt,
        Material* material ) const;
};
#endif // SPHERE_BUILDER_H_
