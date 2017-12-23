#include "ShapeOffPageException.h"

ShapeOffPageException::ShapeOffPageException(unsigned int xLocationValue,
                                             unsigned int yLocationValue,
                                             const string& what_arg)
    : out_of_range(what_arg),
      originalXLocation(xLocationValue),
      originalYLocation(yLocationValue) {}
