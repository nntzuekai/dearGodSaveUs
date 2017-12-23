#include "ShapeYPartOffPageException.h"

ShapeYPartOffPageException::ShapeYPartOffPageException(
    unsigned int xLocationValue, unsigned int yLocationValue,
    unsigned int dimension1Value, unsigned int truncatedDimension1Value,
    unsigned int heightValue, unsigned int truncatedHeightValue,
    const string& what_arg)
    : out_of_range(what_arg),
      originalXLocation(xLocationValue),
      originalYLocation(yLocationValue),
      originalDimension1(dimension1Value),
      truncatedDimension1(truncatedDimension1Value),
      originalHeight(heightValue),
      truncatedHeight(truncatedHeightValue) {}
