#include "Builder.hpp"

Builder::Builder ( std::string const& ID ) :
  ID_ (ID)
{ }

std::string Builder::getID () const { return ID_; }
