#ifndef PNGHANDLER_H_
#define PNGHANDLER_H_
#include "ImageHandler.hpp"

using namespace std;

class PNGHandler : public ImageHandler {
  public:
    void Save ( Image const& img, string const& filename );

    virtual Image* Load ( std::string const& filename ) = 0;
};
#endif
