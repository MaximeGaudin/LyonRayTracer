#include "exceptions.hpp"
#include <cstdlib>
#include <iostream>

void logException ( std::string const& message ) {
  std::cerr << "CRITICAL EXCEPTION : " << message << std::endl;
	exit(1);
}

void logException ( std::string const& launcher, std::string const& message ) {
  std::cerr << launcher; 
  logException ( message );
	exit(1);
}

void logInformation ( std::string const& launcher, std::string const& message ) {
  std::cout << "[" << launcher << "] - " << message << std::endl;
}
