#ifndef JPGWRITER_H_
#define JPGWRITER_H_
#include "ImageWriter.hpp"

using namespace std;

template <typename P>
class JPGWriter : public ImageWriter<P> {
  public:
    void Save ( Image<P> const& img, string filename );
};
#endif
