/**
  * @file Scene.hpp
  * @author Maxime Gaudin.
  * @date 2011
  *
  * Classe permettant de gérer une scène. Une scène est composée de :
  * - Une seule caméra,
  * - un ensemble de lumières,
  * - un ensemble de géométries,
  * - une couleur ambiente,
  * - une image où écrire le rendu.
  */
#ifndef SCENE_H_
#define SCENE_H_
#include <Color.hpp>

class Camera;
class Light;
class Geometry;
class Image;

struct Scene {
  Camera* camera;
  vector<Light*> lights;
  vector<Geometry*> geometries;

  Color_d ambient;

  Image* frame;
};
#endif // SCENE_H_
