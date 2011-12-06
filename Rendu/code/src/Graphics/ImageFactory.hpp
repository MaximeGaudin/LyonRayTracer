/**
  * @file ImageFactory.hpp
  * @author Maxime Gaudin
  * @date 2011
  *
  * Cette classe est une usine à image. Elle permet, sans avoir à se préocupper
  * du handler, de charger ou sauvergarder une image sous un format supporté par
  * l'application.
  */
#ifndef IMAGE_FACTORY_H_
#define IMAGE_FACTORY_H_
#include <vector>
#include <string>

#include <Image.hpp>

class ImageHandler;

class ImageFactory {
  public:
    /**
      * Ajoute un handler à la liste des handlers disponibles.
      * 
      * @param Handler à ajouter.
      */
    static void addHandler ( ImageHandler* handler );

    /**
      * Sauvergarde l'image.
      *
      * @param img Image à sauvegarder.
      * @param filename Destination de la nouvelle image.
      */
    static void Save ( Image const& img, string const& filename );
    
    /** 
      * Charge une image
      *
      * @param filename Chemin de l'image à charger.
      * @return L'image nouvellement crée ou un pointeur nulle si le
      * format est invalide ou l'image inexistante.
      */
    static Image* Load ( std::string const& filename );

  private:
    static std::vector<ImageHandler*> handlers_;

};
#endif // IMAGE_FACTORY_H_
