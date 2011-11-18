#ifndef JPGHANDLER_H_
#define JPGHANDLER_H_
#include "ImageHandler.hpp"

using namespace std;

class JPGHandler : public ImageHandler {
  public:
    void Save ( Image const& img, string const& filename );
    
    virtual Image* Load ( std::string const& filename ) = 0;
};
#endif
