#include "PNGWriter.hpp"
#include <Image.cc>

#include <CImg.h>

using namespace cimg_library;

template <typename P>
void PNGWriter<P>::Save ( Image<P> const& img, string filename ) {
  CImg<P> result(img.W(), img.H(), 1, 3, 0);  
 
  for ( unsigned int X = 0; X < img.W(); ++X ) {
    for ( unsigned int Y = 0; Y < img.H(); ++Y ) {
      Color<P> C (img[X][Y]);
      double CArray[3] = { C.R(), C.G(), C.B() };
      result.draw_point ( X, Y, CArray );
    }
  }

  result.save_png ( filename.c_str() );
}
