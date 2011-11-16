#ifndef PERSPECTIVE_BUILDER_H_
#define PERSPECTIVE_BUILDER_H_
#include <Builder.hpp>

#include <string>
#include <boost/property_tree/ptree.hpp>

class Buildable;

class PerspectiveBuilder : public Builder {
  public:
    PerspectiveBuilder ();

  public:
    Buildable* getObject( 
        boost::property_tree::ptree pt,
        Material* material ) const;
};
#endif // PERSPECTIVE_BUILDER_H_
