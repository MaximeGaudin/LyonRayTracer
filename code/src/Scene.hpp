#ifndef SCENE_H_
#define SCENE_H_
#include <Camera.hpp>
#include <Geometry.hpp>
#include <Light.hpp>
#include <Image.hpp>

struct Scene {
  Camera* camera;
  vector<Light*> lights;
  vector<Geometry*> geometries;

  Color_d ambient;

  Image* frame;
};
#endif // SCENE_H_
