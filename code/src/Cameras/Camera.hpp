#ifndef CAMERA_H_
#define CAMERA_H_
#include <Ray.hpp>
#include <vector>

using namespace std;

class Camera {
  public:
    Camera ( unsigned int resX, unsigned int resY ) : resX_(resX), resY_(resY) {}

    vector<Ray>::const_iterator begin() { return rayCollection_.begin(); }
    vector<Ray>::const_iterator end() { return rayCollection_.end(); }

  protected:
    unsigned int resX_;
    unsigned int resY_;

    vector <Ray> rayCollection_;
};
#endif // CAMERA_H_
