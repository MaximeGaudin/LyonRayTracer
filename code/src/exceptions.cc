#include "exceptions.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;

void logException ( string message ) {
	cerr << "CRITICAL EXCEPTION : " << message << endl;
	exit(1);
}
