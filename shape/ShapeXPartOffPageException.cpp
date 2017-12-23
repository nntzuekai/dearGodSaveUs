#include "ShapeXPartOffPageException.h"

ShapeXPartOffPageException::ShapeXPartOffPageException(
    unsigned int xLocationValue, unsigned int yLocationValue,
    unsigned int dimension1Value, unsigned int truncatedDimension1Value,
    const string& what_arg)
    : out_of_range(what_arg),
      originalXLocation(xLocationValue),
      originalYLocation(yLocationValue),
      originalDimension1(dimension1Value),
      truncatedDimension1(truncatedDimension1Value) {}
