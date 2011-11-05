#ifndef JPGWRITER_H_
#define JPGWRITER_H_
#include "ImageWriter.hpp"

using namespace std;

class JPGWriter : public ImageWriter {
  public:
    void Save ( Image const& img, string const& filename );
};
#endif
