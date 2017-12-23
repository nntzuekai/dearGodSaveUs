#include "Frame.h"

Frame::Frame() {}

Frame::Frame(const Frame& frameToCopy) {
  for (auto iter = frameToCopy.shapesInPicture.begin();
       iter != frameToCopy.shapesInPicture.end(); ++iter) {
    auto r_ptr = dynamic_cast<Rectangle*>(*iter);
    auto t_ptr = dynamic_cast<Triangle*>(*iter);
    auto g_ptr = dynamic_cast<Gasket*>(*iter);
    if (r_ptr) {
      auto new_ptr = new Rectangle(*r_ptr);
      shapesInPicture.push_back(dynamic_cast<Shape*>(new_ptr));
    } else if (t_ptr) {
      auto new_ptr = new Triangle(*t_ptr);
      shapesInPicture.push_back(dynamic_cast<Shape*>(new_ptr));
    } else if (g_ptr) {
      auto new_ptr = new Gasket(*g_ptr);
      shapesInPicture.push_back(dynamic_cast<Shape*>(new_ptr));
    }
  }
}

Frame::~Frame() {
  for (auto iter = shapesInPicture.begin(); iter != shapesInPicture.end();
       ++iter) {
    delete *iter;
  }
}