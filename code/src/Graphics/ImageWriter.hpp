/**
  * @file ImageWriter.hpp
  * @brief Interface d'un exporteur d'image.
  * @author Maxime Gaudin
  * @date 2011
  */
#ifndef IMAGE_WRITER_H
#define IMAGE_WRITER_H
#include <Image.cc>

#include <string>

using namespace std;

template <typename P>
class ImageWriter {
  public:
  /**
    * Cette fonction sauvegarde l'image passée en paramètre.
    *
    * @param img Image à écrire.
    * @param filename Nom du fichier où l'image sera écrite.
    */
  virtual void Save ( Image<P> const& img, string filename ) = 0;
};
#endif // IMAGE_WRITER_H
