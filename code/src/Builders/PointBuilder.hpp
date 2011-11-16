#ifndef POINT_BUILDER_H_
#define POINT_BUILDER_H_
#include <Builder.hpp>

#include <string>
#include <boost/property_tree/ptree.hpp>

class Buildable;

class PointBuilder : public Builder {
  public:
    PointBuilder ();

  public:
    Buildable* getObject( 
        boost::property_tree::ptree pt,
        Material* material ) const;
};
#endif // POINT_BUILDER_H_
