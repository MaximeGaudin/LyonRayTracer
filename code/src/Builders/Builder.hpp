#ifndef BUILDER_H_
#define BUILDER_H_
#include <string>
#include <boost/property_tree/ptree.hpp>

class Buildable;
class Material;

class Builder {
  public:
    Builder ( std::string const& ID );

  public:
    virtual Buildable* getObject( 
        boost::property_tree::ptree pt,
        Material* material ) const = 0;

  public:
    std::string getID () const;

  protected:
    std::string ID_;
};
#endif // BUILDER_H_
