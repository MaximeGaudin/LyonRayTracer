/**
  * @file Sampler.hpp
  * @author Maxime Gaudin
  * @date 2011
  *
  * Les samplers ont pour objectif d'échantillonner le nombre de rayons 
  * lancés pour chaque pixel.
  */
#ifndef SAMPLER_H_
#define SAMPLER_H_
#include <vector>

#include <Ray.hpp>
#include <Scene.hpp>

class Sampler {
  public:
    /**
      * @return Ensemble des rayons à lancer pour la scène et les 
      * coordonnées passés en paramètres.
      */
    virtual std::vector<Ray> getRays ( Scene const& scene, 
        unsigned int X, unsigned int Y ) = 0;
};
#endif
