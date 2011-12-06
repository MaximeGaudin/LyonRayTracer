#include "JPGHandler.hpp"

#include <Color.hpp>

#include <cstdio>
#include <cstdlib>

#include <jpeglib.h>

#include <exceptions.hpp>

void JPGHandler::Save ( Image const& img, string const& filename ) {
	struct jpeg_compress_struct cinfo;
	struct jpeg_error_mgr jerr;

  unsigned char *raw_image = new unsigned char [ 3 * img.W() * img.H() ];
	
	JSAMPROW row_pointer[1];
	FILE *outfile = fopen( filename.c_str(), "wb" );
	if ( !outfile ) {
    logException ( "JPGWriter", "Can't open file." );
  }

	cinfo.err = jpeg_std_error( &jerr );
	jpeg_create_compress(&cinfo);
	jpeg_stdio_dest(&cinfo, outfile);

	cinfo.image_width = img.W();	
	cinfo.image_height = img.H();
	cinfo.input_components = 3;
	cinfo.in_color_space = JCS_RGB;

	jpeg_set_defaults( &cinfo );
	jpeg_start_compress( &cinfo, TRUE );
  for ( unsigned int Y = 0; Y < img.H(); ++Y ) {
    for ( unsigned int X = 0; X < img.W(); ++X ) {
      Color<double> C (img[X][Y]); 
      unsigned char R = C.R() * 255.0;
      unsigned char G = C.G() * 255.0;
      unsigned char B = C.B() * 255.0;

      raw_image[Y * img.W() + 3 * X] = R; 
      raw_image[Y * img.W() + 3 * X + 1] = G;
      raw_image[Y * img.W() + 3 * X + 2] = B;
  }

		row_pointer[0] = &raw_image[ Y * img.W() ];
		jpeg_write_scanlines( &cinfo, row_pointer, 1 );
	}

	jpeg_finish_compress( &cinfo );
	jpeg_destroy_compress( &cinfo );
	fclose( outfile );

  delete[] raw_image;
}
