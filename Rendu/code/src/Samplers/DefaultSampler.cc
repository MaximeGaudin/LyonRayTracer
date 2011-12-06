#include "DefaultSampler.hpp"
#include <Image.hpp>
#include <Camera.hpp>

std::vector<Ray> DefaultSampler::getRays ( Scene const& scene,
    unsigned int X, unsigned int Y ) {
  double u = (double)X / (double)scene.frame->W();
  double v = (double)Y / (double)scene.frame->H();

  return scene.camera->getRay(u,v);
}
