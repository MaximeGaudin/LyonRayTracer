#ifndef IMAGE_TI_H_
#define IMAGE_TI_H_
#include "Image.hpp"

#include <exceptions.hpp>

// Ctor & Dtor
Image::Image (unsigned int width, unsigned int height) : 
  w_ (width),
  h_ (height)
{
  pixelsData_ = new Color<double>* [ width ];
  for ( unsigned int X = 0; X < width; ++X ) 
    pixelsData_[X] = new Color<double> [ height ];

  logInformation ("Image", 
      str( format ("Building new output frame (%1%, %2%)... OK")
          % width % height ) );
}

Image::~Image () {
  for ( unsigned int X = 0; X < w_; ++X ) delete[] pixelsData_[X];
  delete[] pixelsData_;
}

// Operator
Color<double>* Image::operator [] ( unsigned int i ) {
  return pixelsData_[i];
}

Color<double>* Image::operator [] ( unsigned int i ) const {
  return pixelsData_[i];
}

// Getters 
unsigned int Image::W() const { return w_; }
unsigned int Image::H() const { return h_; }
#endif // IMAGE_TI_H_
