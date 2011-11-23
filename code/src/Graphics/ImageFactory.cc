#include "ImageFactory.hpp"

#include <exceptions.hpp>
#include <PNGHandler.hpp>

std::vector<ImageHandler*> ImageFactory::handlers_ = std::vector<ImageHandler*>();

void ImageFactory::addHandler ( ImageHandler* handler ) {
  ImageFactory::handlers_.push_back ( handler );
}

void ImageFactory::Save ( Image const& img, string const& filename ) {
  std::vector < ImageHandler* >::const_iterator it = ImageFactory::handlers_.begin();

  while ( it != ImageFactory::handlers_.end() ) {
    if ( (*it)->Validate ( filename ) ) {
      (*it)->Save ( img, filename );
      return ;
    }

    ++it;
  }
}
    
Image* ImageFactory::Load ( std::string const& filename ) {
   std::vector < ImageHandler* >::const_iterator it = ImageFactory::handlers_.begin();

  while ( it != ImageFactory::handlers_.end() ) {
    if ( (*it)->Validate ( filename ) )
      return (*it)->Load ( filename );

    ++it;
  } 
  
  logException ("ImageFactory", "No viable reader found!");
  return NULL;
}

