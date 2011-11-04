#ifndef PNGWRITER_H_
#define PNGWRITER_H_
#include "ImageWriter.hpp"

using namespace std;

template <typename P>
class PNGWriter : public ImageWriter<P> {
  public:
  void Save ( Image<P> const& img, string filename );
};
#endif
