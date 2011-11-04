#ifndef IMAGE_TI_H_
#define IMAGE_TI_H_
#include "Image.hpp"

// Ctor & Dtor
template < typename P >
Image<P>::Image (unsigned int width, unsigned int height) 
  : w_ (width)
    , h_ (height)
{
  pixelsData_ = new Color<P>* [ width ];
  for ( unsigned int X = 0; X < width; ++X ) 
    pixelsData_[X] = new Color<P> [ height ];
}

template < typename P >
Image<P>::~Image () {
  for ( unsigned int X = 0; X < w_; ++X ) delete[] pixelsData_[X];
  delete[] pixelsData_;
}

// Operator
template < typename P >
Color<P>* Image<P>::operator [] ( unsigned int i ) {
  return pixelsData_[i];
}

template < typename P >
Color<P>* Image<P>::operator [] ( unsigned int i ) const {
  return pixelsData_[i];
}

// Getters 
template < typename P >
unsigned int Image<P>::W() const { return w_; }

template < typename P >
unsigned int Image<P>::H() const { return h_; }
#endif // IMAGE_TI_H_
