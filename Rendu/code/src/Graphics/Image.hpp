/**
  * @file Image.hpp
  * @brief Ce header contient la déclaration de la classe Image.
  *
  * @author Maxime Gaudin
  * @date 2011
  *
  * Cette classe permet d'abstraire la notion d'image et de créer un format 
  * générique utilisable par tous et notamment par les handlers.
  * La classe Image est paramétré par le type de couleur qu'elle devra contenir
  * et les pixels sont stockés sur des axes partant du coin supérieur gauche.
  */
#ifndef IMAGE_H_
#define IMAGE_H_
#include <Color.hpp>

class Image {
  public: // Ctor && Dtor
    /**
      * @param width Largeur de l'image.
      * @param height Hauteur de l'image.
      */
    Image (unsigned int width, unsigned int height);

    /**
      * @param pixelsData Tableau contenant l'ensemble des pixels avec pour 
      * origine (0,0) le coin supérieur gauche de l'image.
      */
    Image (Color<double>** const& pixelsData);

    ~Image ();

  public: // Operators 
    Color<double>* operator [] ( unsigned int i );
    Color<double>* operator [] ( unsigned int i ) const;

  public: // Getters
    /**
      * @return La largeur de l'image.
      */
    unsigned int W() const;

    /**
      * @return La hauteur de l'image.
      */
    unsigned int H() const;

  private:
    Color<double>** pixelsData_;
    unsigned int w_, h_;
};
#endif // IMAGE_H_
