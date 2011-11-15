#ifndef SAMPLER_H_
#define SAMPLER_H_
#include <vector>

#include <Ray.hpp>
#include <Scene.hpp>

class Sampler {
  public:
    virtual std::vector<Ray> getRays ( Scene const& scene, 
        unsigned int X, unsigned int Y ) = 0;
};
#endif
