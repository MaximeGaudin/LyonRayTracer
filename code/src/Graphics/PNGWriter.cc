#include "PNGWriter.hpp"
#include <Image.cc>

template <typename P>
void PNGWriter<P>::Save ( Image<P> const& img, string filename ) {
  for ( unsigned int X = 0; X < img.W(); ++X ) {
    for ( unsigned int Y = 0; Y < img.H(); ++Y ) {
      Color<P> C (img[X][Y]);
      P CArray[3] = { C.R(), C.G(), C.B() };
    }
  }
}
