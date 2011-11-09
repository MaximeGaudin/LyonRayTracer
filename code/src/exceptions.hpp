#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <string>

#include <boost/format.hpp>

using namespace std;
using boost::format;
using boost::io::group;

using namespace std;

#define VECTOR_OUT_OF_BOUNDS_EXCEPTION_MESSAGE		"VECTOR_OUT_OF_BOUNDS_EXCEPTION"

void logException ( string message );
void logException ( string launcher, string message );

void logInformation ( string launcher, string message );
#endif
