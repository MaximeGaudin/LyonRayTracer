/**
  * @file ImageHandler.hpp
  * @brief Interface d'un exporteur d'image.
  * @author Maxime Gaudin
  * @date 2011
  */
#ifndef IMAGE_HANDLER_H
#define IMAGE_HANDLER_H
#include <Image.hpp>
#include <string>

class ImageHandler {
  public:
  /**
    * Cette fonction sauvegarde l'image passée en paramètre.
    *
    * @param img Image à écrire.
    * @param filename Nom du fichier où l'image sera écrite.
    */
  virtual void Save ( Image const& img, std::string const& filename ) = 0;

  virtual Image* Load ( std::string const& filename ) = 0;

  virtual bool Validate ( std::string const& filename ) = 0;
};
#endif // IMAGE_HANDLER_H
