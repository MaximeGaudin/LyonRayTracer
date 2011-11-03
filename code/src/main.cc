#include <Ray.cc>
#include <Matrix.cc>

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

  return 0;
}
