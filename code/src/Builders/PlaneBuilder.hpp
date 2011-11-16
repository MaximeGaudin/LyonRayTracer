#ifndef PLANE_BUILDER_H_
#define PLANE_BUILDER_H_
#include <Builder.hpp>

#include <string>
#include <boost/property_tree/ptree.hpp>

class Buildable;

class PlaneBuilder : public Builder {
  public:
    PlaneBuilder ();

  public:
    Buildable* getObject( 
        boost::property_tree::ptree pt,
        Material* material ) const;
};
#endif // PLANE_BUILDER_H_
