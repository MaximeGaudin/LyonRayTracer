/**
  * @file exceptions.hpp
  * @author Maxime Gaudin
  * @date 2011
  *
  * Ce fichier déclare des fonctions d'aide permettant de normaliser l'accès
  * aux méchanisme de journalisation.
  */
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
