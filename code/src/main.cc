#include <Ray.cc>
#include <Maths.hpp>
#include <Color.cc>
#include <Image.cc>
#include <JPGWriter.cc>
#include <PNGWriter.cc>

#include <iostream>

using namespace std;

int main () {
  Ray < double, 2 > newRay 
    ( Vector<double, 2> (2) , Vector< double, 2>(3) );
  cout << newRay << endl;

  Matrix < double, 4, 4 > M ( IDENTITY );
  cout << M << endl;

  Matrix < double, 4, 4 > M2 ( Matrix<double, 4, 4>::RotationX ( 2.3 ) );
  cout << M2 << endl;
  
  cout << ( M * M2 ) << endl;
  cout << Matrix< double, 4, 4 >::Rotation ( 1, 2, 3 ) << endl;

  cout << Matrix < double, 4, 4>::Translation ( 1, 1, 1 ) << endl;
  cout << Matrix < double, 4, 4>::Scale ( 1, 1, 1 ) << endl;

  Color<double> c (1.0);
  cout << c << endl;

  Color<double> c2 (1,0.5, .01);
  cout << c2 << endl;

  cout << (c + c2) << endl;
  cout << (c - c2) << endl;
  cout << (c * c2) << endl;

  Image<double>img ( 500, 500 );
  for ( unsigned int X = 0; X < img.W(); ++X )
    for ( unsigned int Y = 0; Y < img.H(); ++Y ) 
      img [X][Y] = Color<double> ( 1, 0, (double)Y / (double)img.H() );

  JPGWriter<double> IW; IW.Save ( img, "test.jpg" );
  PNGWriter<double> IW2; IW2.Save ( img, "test.png" );
  return 0;
}
