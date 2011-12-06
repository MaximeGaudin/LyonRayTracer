#include "PNGHandler.hpp"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>

#include <Color.hpp>

#include <png.h>

#include <exceptions.hpp>

using namespace std;

void PNGHandler::Save ( Image const& img, string const& filename ) {
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
  if (!fp) logException ( "PNGwriter", "Can't open file." );

  png_structp png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
  if (!png_ptr) logException("PNGHandler", "Export failed.");

  png_infop info_ptr = png_create_info_struct(png_ptr);
  if (!info_ptr) logException("PNGHandler", "Export failed.");

  if (setjmp(png_jmpbuf(png_ptr))) logException("PNGHandler", "Export failed.");
  png_init_io(png_ptr, fp);

  if (setjmp(png_jmpbuf(png_ptr))) logException("PNGHandler", "Export failed.");

  png_set_IHDR(png_ptr, info_ptr, img.W(), img.H(),
      8, PNG_COLOR_TYPE_RGB, PNG_INTERLACE_NONE,
      PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);
  png_write_info(png_ptr, info_ptr);

  if (setjmp(png_jmpbuf(png_ptr))) logException("PNGHandler", "Export failed.");
  png_write_image(png_ptr, row_pointers);

  if (setjmp(png_jmpbuf(png_ptr))) logException("PNGHandler", "Export failed.");
  png_write_end(png_ptr, NULL);

  fclose(fp);

  free(row_pointers);
}

bool PNGHandler::Validate(std::string const& filename) {
  if ( filename.substr ( filename.length() - 3,  3 ) == "png" ) return true;

  return false;
}

Image* PNGHandler::Load ( std::string const& filename ) {
  if (!Validate(filename))
    logException ( "PNGwriter", "Can't open file or wrong file format." );

  FILE* inputFile = fopen (filename.c_str(), "rb");

  png_structp pngPtr = 
    png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
  if (!pngPtr) logException("PNGHandler", "Export failed.");

  png_infop infoPtr = png_create_info_struct(pngPtr);
  if (!pngPtr) {
    png_destroy_read_struct(&pngPtr, (png_infopp)0, (png_infopp)0);
    logException("PNGHandler", "Export failed.");
  }

  if (setjmp(png_jmpbuf(pngPtr)))
    logException("PNGHandler", "Export failed.");

  png_init_io ( pngPtr, inputFile );
  png_read_info ( pngPtr, infoPtr );
  unsigned int width = png_get_image_width(pngPtr, infoPtr);
  unsigned int height = png_get_image_height(pngPtr, infoPtr);
  unsigned int color_type = png_get_color_type(pngPtr, infoPtr);
  unsigned int bit_depth = png_get_bit_depth(pngPtr, infoPtr);

  unsigned int number_of_passes = png_set_interlace_handling(pngPtr);

  png_read_update_info(pngPtr, infoPtr);

  png_bytep* row_pointers = (png_bytep*) malloc(sizeof(png_bytep) * height);
  for (int y = 0; y < height; ++y)
    row_pointers[y] = (png_byte*) malloc(png_get_rowbytes(pngPtr,infoPtr));

  png_read_image(pngPtr, row_pointers);

  Image* img = new Image ( width, height );

  for ( unsigned int Y = 0; Y < img->H(); ++Y ) {
    for ( unsigned int X = 0; X < img->W(); ++X ) {
      unsigned char R = row_pointers[Y][3 * X]; 
      unsigned char G = row_pointers[Y][3 * X + 1];
      unsigned char B = row_pointers[Y][3 * X + 2]; 

      (*img)[X][Y] = Color_d (
          (double)R / 255.0,
          (double)G / 255.0,
          (double)B / 255.0);
    }
  }

  fclose (inputFile );

  return img;
}
