#include "PNGWriter.hpp"

#include <iostream>
#include <cstdlib>
#include <cstdio>

#include <Color.hpp>

#include <png.h>

using namespace std;

void PNGWriter::Save ( Image const& img, string const& filename ) {
 png_bytep* row_pointers = (png_bytep*) malloc( sizeof(png_bytep) * img.H() );

  for ( unsigned int Y = 0; Y < img.H(); ++Y ) {
    row_pointers[Y] = (png_byte*) malloc( sizeof(png_byte) * 3 * img.W() );

    for ( unsigned int X = 0; X < img.W(); ++X ) {
      Color<double> C (img[X][Y]); 
      unsigned char R = C.R() * 255.0;
      unsigned char G = C.G() * 255.0;
      unsigned char B = C.B() * 255.0;

      row_pointers[Y][3 * X] = R; 
      row_pointers[Y][3 * X + 1] = G;
      row_pointers[Y][3 * X + 2] = B; 
    }
  }

  FILE *fp = fopen(filename.c_str(), "wb");
  if (!fp) cout << "Error" << endl;

  png_structp png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
  if (!png_ptr) cout << "Error" << endl;

  png_infop info_ptr = png_create_info_struct(png_ptr);
  if (!info_ptr) cout << "Error" << endl;

  if (setjmp(png_jmpbuf(png_ptr))) cout << "Error" << endl;
  png_init_io(png_ptr, fp);

  if (setjmp(png_jmpbuf(png_ptr))) cout << "Error" << endl;

  png_set_IHDR(png_ptr, info_ptr, img.W(), img.H(),
      8, PNG_COLOR_TYPE_RGB, PNG_INTERLACE_NONE,
      PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);
  png_write_info(png_ptr, info_ptr);

  if (setjmp(png_jmpbuf(png_ptr))) cout << "Error" << endl;
  png_write_image(png_ptr, row_pointers);

  if (setjmp(png_jmpbuf(png_ptr))) cout << "Error" << endl;
  png_write_end(png_ptr, NULL);

  fclose(fp);

 free(row_pointers);
}
