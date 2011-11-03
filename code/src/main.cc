#include <Ray.cc>
#include <Maths.hpp>
#include <Color.cc>

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

  return 0;
}
