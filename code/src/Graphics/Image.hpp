#ifndef IMAGE_H_
#define IMAGE_H_
#include <Color.cc>

template < typename P >
class Image {
  public: // Ctor && Dtor
    Image (unsigned int width, unsigned int height);
    ~Image ();

  public: // Operators 
    Color<P>* operator [] ( int i );

  public: // Getters
    unsigned int W() const;
    unsigned int H() const;

  private:
    Color<P>** pixelsData_;
    unsigned int w_, h_;
};
#endif // IMAGE_H_
