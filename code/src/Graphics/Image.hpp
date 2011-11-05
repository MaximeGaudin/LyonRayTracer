/**
  * @file Image.hpp
  * @brief Ce header contient la déclaration de la classe Image.
  *
  * @author Maxime Gaudin
  * @date 2011
  *
  * La classe Image est paramétré par le type de couleur qu'elle devra contenir
  * et les pixels sont stockés sur des axes partant du coin supérieur gauche.
  */
#ifndef IMAGE_H_
#define IMAGE_H_
#include <Color.hpp>

class Image {
  public: // Ctor && Dtor
    /**
      * Constructeur d'Image.
      *
      * @param width Largeur de l'image.
      * @param height Hauteur de l'image.
      */
    Image (unsigned int width, unsigned int height);

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
