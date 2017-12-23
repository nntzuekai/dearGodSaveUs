#include "Shape.h"
#include <cctype>
#include <tuple>
unsigned int Shape::shapesCreated = 0;
unsigned int Shape::shapesExisting = 0;
Shape::Shape() : Shape(10, 10, 100, Colour(0, 0, 0, 255)) {}

Shape::Shape(const Shape &toBeCopied)
    : Shape(toBeCopied.xLocation, toBeCopied.yLocation, toBeCopied.dimension1,
            toBeCopied.shapeColour) {}
Shape::Shape(unsigned int xLocationValue, unsigned int yLocationValue,
             unsigned int dimension1Value, Colour blockColourValue)
    : xLocation(xLocationValue),
      yLocation(yLocationValue),
      dimension1(dimension1Value),
      shapeColour(blockColourValue) {
  ++shapesCreated;
  ++shapesExisting;
}

Shape::Shape(unsigned int xLocationValue, unsigned int yLocationValue,
             Colour blockColourValue)
    : Shape(xLocationValue, yLocationValue, 100, blockColourValue) {}

Shape::~Shape() { Shape::shapesExisting--; }

unsigned int Shape::GetXLocation() const { return this->xLocation; }
unsigned int Shape::GetYLocation() const { return this->yLocation; }
unsigned int Shape::GetDimension1() const { return this->dimension1; }
Colour Shape::GetShapeColour() const { return this->shapeColour; }
unsigned int Shape::GetShapesCreated() { return Shape::shapesCreated; }
unsigned int Shape::GetShapesExisting() { return Shape::shapesExisting; }

void Shape::SetXLocation(const unsigned int xLocationValue) {
  this->xLocation = xLocationValue;
}
void Shape::SetYLocation(const unsigned int yLocationValue) {
  this->yLocation = yLocationValue;
}
void Shape::SetDimension1(const unsigned int setDimension1Value) {
  this->dimension1 = setDimension1Value;
}
void Shape::SetShapeColour(const Colour blockColourValue) {
  this->shapeColour = blockColourValue;
}
void Shape::SetShapesCreated(unsigned int numberCreated) {
  Shape::shapesCreated = numberCreated;
}
void Shape::SetShapesExisting(unsigned int numberExisting) {
  Shape::shapesExisting = numberExisting;
}

void Shape::SetIfDebug(unsigned int ifDebugValue) {
  Shape::ifDebug = ifDebugValue;
}

unsigned int Shape::GetIfDebug() { return Shape::ifDebug; }

ostream &operator<<(ostream &os, const Shape &myShape) {
  os << setw(20) << "Shapes Created " << setw(9) << Shape::shapesCreated
     << endl;
  os << setw(20) << "Shapes Existing " << setw(9) << Shape::shapesExisting
     << endl;
  return os;
}

const Shape &Shape::operator=(const Shape &shape2) {
  this->xLocation = shape2.xLocation;
  this->yLocation = shape2.yLocation;
  this->dimension1 = shape2.dimension1;
  this->shapeColour = shape2.shapeColour;
  return *this;
}

bool Shape::operator==(const Shape &shape2) const {
  return tie(xLocation, yLocation, dimension1, shapeColour) ==
         tie(shape2.xLocation, shape2.yLocation, shape2.dimension1,
             shape2.shapeColour);
}
void Shape::CheckOffPage(string objectTypeName) {
  if (this->xLocation > pageWidth || this->yLocation > pageLength) {
    if (ifDebug == 0 || ifDebug > 2) {
      this->xLocation = 0;
      this->yLocation = 0;
    } else if (ifDebug == 1) {
      this->xLocation = 0;
      this->yLocation = 0;
      cout << objectTypeName << " object is off the page" << endl;
      cout << "X position and Y position have been reset to 0" << endl;
    } else if (ifDebug == 2) {
      unsigned int originalXLocation, originalYLocation;
      originalXLocation = xLocation;
      originalYLocation = yLocation;
      xLocation = 0;
      yLocation = 0;
      throw ShapeOffPageException(originalXLocation, originalYLocation);
    }
  }
}

void Shape::CheckXPartOffPage(string objectTypeName) {
  if (this->xLocation + this->dimension1 > pageWidth) {
    cout << objectTypeName << " object partially off the page" << endl;
    cout << "X dimension reset to include only the part of ";
    objectTypeName[0] = tolower(objectTypeName[0]);
    cout << objectTypeName << " on the page" << endl;
    cout << "X dimension was " << this->dimension1;
    this->dimension1 = pageWidth - this->xLocation;
    cout << " X dimension is " << this->dimension1;
  }
}
