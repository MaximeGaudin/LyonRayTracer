#include "exceptions.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;

void logException ( string message ) {
	cerr << "CRITICAL EXCEPTION : " << message << endl;
	exit(1);
}

void logException ( string launcher, string message ) {
  cerr << launcher; 
  logException ( message );
	exit(1);
}

void logInformation ( string launcher, string message ) {
  cout << "[" << launcher << "] - " << message << endl;
}
