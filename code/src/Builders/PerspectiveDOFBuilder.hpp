/**
  * @file PerspectiveDOFBuilder.hpp
  * @author Maxime Gaudin
  * @date 2011
  *
  * Builder associé à l'objet PerspectiveDOF.
  */
#ifndef PERSPECTIVE_DOF_BUILDER_H_
#define PERSPECTIVE_DOF_BUILDER_H_
#include <Builder.hpp>

#include <string>
#include <boost/property_tree/ptree.hpp>

class Buildable;

class PerspectiveDOFBuilder : public Builder {
  public:
    PerspectiveDOFBuilder ();

  public:
    Buildable* getObject( 
        boost::property_tree::ptree pt,
        Material* material ) const;
};
#endif // PERSPECTIVE_DOF_BUILDER_H_
