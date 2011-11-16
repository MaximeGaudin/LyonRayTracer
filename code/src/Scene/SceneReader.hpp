#ifndef SCENE_READER_H_
#define SCENE_READER_H_
#include <common.hpp>
#include <map>
#include <Scene.hpp>

class Builder;

class SceneReader {
  public:
    void addBuilder ( Builder* builder );
    Scene read ( std::string const& filename ) const;

  private:
    Builder* getBuilder ( std::string const& ID ) const;

  protected:
    std::map<std::string, Builder*> builders_;
};
#endif // SCENE_READER_H_
