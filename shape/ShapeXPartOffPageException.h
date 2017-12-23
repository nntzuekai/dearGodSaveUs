#ifndef SHAPEXPARTOFFPAGE
#define SHAPEXPARTOFFPAGE
#include <exception>
#include <iostream>
#include <string>
using std::cerr;
using std::endl;
using std::out_of_range;
using std::string;
class ShapeXPartOffPageException : public out_of_range {
 public:
  ShapeXPartOffPageException(unsigned int xLocationValue = 0,
                             unsigned int yLocationValue = 0,
                             unsigned int dimension1Value = 0,
                             unsigned int truncatedDimension1Value = 0,
                             const string& what_arg =
                                 "Shape partially off page in X exception: A "
                                 "shape has been truncated in X");

 private:
  unsigned int originalXLocation;
  unsigned int originalYLocation;
  unsigned int originalDimension1;
  unsigned int truncatedDimension1;
};

#endif