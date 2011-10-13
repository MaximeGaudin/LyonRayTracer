#include <Ray.cc>

#include <iostream>

using namespace std;

int main () {
  Ray < double, 2 > newRay 
    ( Vector<double, 2> (2) , Vector< double, 2>(3) );
  cout << newRay << endl;

  return 0;
}
