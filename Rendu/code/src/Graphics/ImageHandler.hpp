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
     * Sauvergarde l'image.
     *
     * @param img Image à sauvegarder.
     * @param filename Destination de la nouvelle image.
     */
    virtual void Save ( Image const& img, std::string const& filename ) = 0;

    /** 
     * Charge une image
     *
     * @param filename Chemin de l'image à charger.
     * @return L'image nouvellement crée ou un pointeur nulle si le
     * format est invalide ou l'image inexistante.
     */
    virtual Image* Load ( std::string const& filename ) = 0;

    /**
      * @return true si la handler est capable de gérer ce format, false
      * sinon.
      */
    virtual bool Validate ( std::string const& filename ) = 0;
};
#endif // IMAGE_HANDLER_H
