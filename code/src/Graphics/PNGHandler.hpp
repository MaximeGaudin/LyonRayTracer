#ifndef PNGHANDLER_H_
#define PNGHANDLER_H_
#include "ImageHandler.hpp"

using namespace std;

class PNGHandler : public ImageHandler {
  public:
    void Save ( Image const& img, string const& filename );

    Image* Load ( std::string const& filename );

    bool Validate ( std::string const& filename );
};
#endif
