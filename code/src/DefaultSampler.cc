#include "DefaultSampler.hpp"

#include <Camera.hpp>

std::vector<Ray> DefaultSampler::getRays ( Scene const& scene,
      unsigned int X, unsigned int Y ) {
  std::vector<Ray> rays;
  double u = (double)X / (double)scene.frame->W();
  double v = 1.0 - (double)Y / (double)scene.frame->H();

  rays.push_back( Ray ( scene.camera->getRay(u, v) ) );

  return rays;
}
