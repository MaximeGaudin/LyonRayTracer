#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <string>

#include <boost/format.hpp>
using boost::format;
using boost::io::group;

void logException ( std::string const& message );
void logException ( std::string const& launcher, std::string const& message );

void logInformation ( std::string const& launcher, std::string const& message );
#endif
