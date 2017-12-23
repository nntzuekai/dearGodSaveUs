#ifndef SHAPEYPARTOFFPAGE
#define SHAPEYPARTOFFPAGE
#include <exception>
#include <iostream>
#include <string>
using std::cerr;
using std::endl;
using std::out_of_range;
using std::string;

class ShapeYPartOffPageException : public out_of_range {
 public:
  ShapeYPartOffPageException(unsigned int xLocationValue = 0,
                             unsigned int yLocationValue = 0,
                             unsigned int dimension1Value = 0,
                             unsigned int truncatedDimension1Value = 0,
                             unsigned int heightValue = 0,
                             unsigned int truncatedHeightValue = 0,
                             const string& what_arg =
                                 "Shape partially off page in Y exception: A "
                                 "shape has been truncated in Y");

 private:
  unsigned int originalXLocation;
  unsigned int originalYLocation;
  unsigned int originalDimension1;
  unsigned int truncatedDimension1;
  unsigned int originalHeight;
  unsigned int truncatedHeight;
};

#endif