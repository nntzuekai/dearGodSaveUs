#ifndef _SHAPEOFFPAGE_
#define _SHAPEOFFPAGE_
#include <exception>
#include <iostream>
#include <string>
using std::cerr;
using std::endl;
using std::out_of_range;
using std::string;
class ShapeOffPageException : public out_of_range {
 public:
  ShapeOffPageException(unsigned int xLocationValue = 0,
                        unsigned int yLocationValue = 0,
                        const string& what_arg =
                            "Shape off page exception: A shape has been moved");

 private:
  unsigned int originalXLocation;
  unsigned int originalYLocation;
};

#endif