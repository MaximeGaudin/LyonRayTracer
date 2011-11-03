#ifndef IMAGE_WRITER_H
#define IMAGE_WRITER_H
#include <Image.cc>

template <typename P>
class ImageWriter {
  static Save ( Image<P> const& img, string filename );
}
#endif // IMAGE_WRITER_H
