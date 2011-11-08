#ifndef DEFAULT_SAMPLER_H_
#define DEFAULT_SAMPLER_H_
#include <Sampler.hpp>

class DefaultSampler : public Sampler {
  public:
  std::vector<Ray> getRays ( Scene const& scene,
      unsigned int X, unsigned int Y );
};
#endif
