#ifndef IMAGE_H_
#define IMAGE_H_

class Image {
  public: // Ctor && Dtor
    Image (unsigned int width, unsigned int heigth);

  public: // Methods
    void write( unsigned int x, unsigned int y, 
        unsigned char r, unsigned char g, unsigned char b );

  private:
    unsigned char* pixelsData;
};
#endif // IMAGE_H_
