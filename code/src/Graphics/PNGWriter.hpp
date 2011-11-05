#ifndef PNGWRITER_H_
#define PNGWRITER_H_
#include "ImageWriter.hpp"

using namespace std;

class PNGWriter : public ImageWriter {
  public:
    void Save ( Image const& img, string const& filename );
};
#endif
