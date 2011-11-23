#ifndef IMAGE_FACTORY_H_
#define IMAGE_FACTORY_H_
#include <vector>
#include <string>

#include <Image.hpp>

class ImageHandler;

class ImageFactory {
  public:
    static void addHandler ( ImageHandler* handler );

    static void Save ( Image const& img, string const& filename );
    
    static Image* Load ( std::string const& filename );

  private:
    static std::vector<ImageHandler*> handlers_;

};
#endif // IMAGE_FACTORY_H_
