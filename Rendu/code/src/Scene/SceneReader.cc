#include "SceneReader.hpp"

#include <exception>
#include <utility>

#include <boost/foreach.hpp>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
using boost::property_tree::ptree;

#include <exceptions.hpp>

#include <Image.hpp>
#include <Camera.hpp>
#include <Material.hpp>
#include <Light.hpp>
#include <Geometry.hpp>

#include <Builder.hpp>

#include <iostream>
using std::cout;
using std::endl;

void SceneReader::addBuilder ( Builder* builder ) 
{
  logInformation("SceneReader", str( format("'%1x' builder added.") 
        % builder->getID() ) );
  builders_.insert ( std::make_pair <std::string, Builder* > 
      ( builder->getID(), builder ) );
}

Scene SceneReader::read ( std::string const& filename ) const 
{
  ptree pt; 
  logInformation ("SceneReader", str( format("Reading scene : %1% ...") % filename)  );
  try {
    read_xml(filename, pt); // A proteger
  }
  catch ( std::exception& e ) {
    logException("SceneReader", 
        str( format("XML Error in %1%") % e.what()) );
  }

  Scene scene;
  scene.materials.insert ( make_pair <std::string, Material*> (
        "DEFAULT_MATERIAL", new Material() ) );

  logInformation("SceneReader", "Image...");
  unsigned int width = pt.get<unsigned int>("scene.<xmlattr>.width");
  unsigned int height = pt.get<unsigned int>("scene.<xmlattr>.height");
  scene.frame= new Image ( width, height );

  logInformation("SceneReader", "Camera...");
  std::string cameraType = pt.get<std::string>("scene.camera.<xmlattr>.type");
  scene.camera = static_cast<Camera*> ( 
      getBuilder ( cameraType )->getObject ( pt.get_child("scene.camera"), NULL) );

  logInformation("SceneReader", "Materials...");
  feach (ptree::value_type &m, pt.get_child("scene.materials")) {
    if (m.first == "material") {
      std::string materialName = m.second.get<std::string>("<xmlattr>.name");
      scene.materials.insert ( 
          std::make_pair<std::string, Material* > ( materialName,
            static_cast<Material*> ( 
              getBuilder ( "material" )->getObject ( m.second, NULL ) ) ) );
    }
  }

  logInformation("SceneReader", "Lights...");
  feach (ptree::value_type &l, pt.get_child("scene.lights")) {
    if (l.first == "light") {
      std::string lightType= l.second.get<std::string>("<xmlattr>.type");
      std::string materialName = l.second.get<std::string>("<xmlattr>.material"
          , "DEFAULT_MATERIAL");

      scene.lights.push_back ( static_cast<Light*> ( 
            getBuilder ( lightType  )->
            getObject ( l.second, scene.materials[materialName] ) ) );
    }
  }

  logInformation("SceneReader", "Geometry...");
  feach (ptree::value_type &g, pt.get_child("scene.geometries")) {
    if (g.first == "geometry") {
      std::string geometryType = g.second.get<std::string>("<xmlattr>.type");
      std::string materialName = g.second.get<std::string>("<xmlattr>.material"
          , "DEFAULT_MATERIAL");

      scene.geometries.push_back ( static_cast<Geometry*> ( 
            getBuilder ( geometryType )->
            getObject ( g.second, scene.materials[materialName] ) ) );
    }
  }

  return scene;
}

Builder* SceneReader::getBuilder ( std::string const& ID ) const 
{
  std::map < std::string, Builder* >::const_iterator it = builders_.find ( ID );
  if ( it == builders_.end() )
    logException ("SceneReader", str ( format("Builder '%1x' not found !") % ID ));

  return it->second;
}
