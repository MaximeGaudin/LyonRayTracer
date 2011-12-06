/**
  * @file Builder.hpp
  * @author Maxime Gaudin
  * @date 2011
  *
  * Ce fichier déclare la classe abstraite de tous les constructeurs d'objets 
  * (d'interface Buildable).
  * C'est ces builders qui seronts passés au SceneReader.
  */
#ifndef BUILDER_H_
#define BUILDER_H_
#include <string>
#include <boost/property_tree/ptree.hpp>

class Buildable;
class Material;

class Builder {
  public:

    /**
      * @param ID Identifiant du type d'objet construit.
      */
    Builder ( std::string const& ID );

  public:
    /**
      * @param pt L'arbre DOM contenant les paramètres du fichier de 
      * configuration de la scène,
      * @param material Matériau associé.
      *
      * @return Un pointeur sur l'objet construit.
      */
    virtual Buildable* getObject( 
        boost::property_tree::ptree pt,
        Material* material ) const = 0;

  public:
    std::string getID () const;

  protected:
    std::string ID_;
};
#endif // BUILDER_H_
