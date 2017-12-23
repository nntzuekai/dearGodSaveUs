// Author: Janice Regan  2017

#ifndef ShapeFlag
#define ShapeFlag

#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
#include "Colour.h"
#include "Shape.h"
#include "ShapeOffPageException.h"
#include "ShapeXPartOffPageException.h"
#include "ShapeYPartOffPageException.h"
using namespace std;

class Shape {
 public:
  // default constructor: no arguments, no return type
  // define if class has any other constructors, or if class
  // includes deep memory (pointers) or static counters
  Shape();
  // copy constructor: needed for function calls
  Shape(const Shape &toBeCopied);
  // other intializing constructors
  Shape(unsigned int xLocationValue, unsigned int yLocationValue,
        unsigned int dimension1Value, Colour blockColourValue);
  Shape(unsigned int xLocationValue, unsigned int yLocationValue,
        Colour blockColourValue);
  // destructor: define when class has deep memory or static counters
  virtual ~Shape();

  // accessor functions
  unsigned int GetXLocation() const;
  unsigned int GetYLocation() const;
  unsigned int GetDimension1() const;
  Colour GetShapeColour() const;
  virtual unsigned int GetHeight() const = 0;
  // accessor functions for static members are static functions
  // this allows the static members to be accessed before any
  // object of the class are created
  static unsigned int GetShapesCreated();
  static unsigned int GetShapesExisting();
  static unsigned int GetIfDebug();

  // mutator functions, in an actual application you would
  // write mutator functions only for member variable that
  // NEED to be accessed from outside the class, This would
  // be the smallest subSet of member variables possible
  //(to preserve encapsulation)
  void SetXLocation(const unsigned int xLocationValue);
  void SetYLocation(const unsigned int yLocationValue);
  void SetDimension1(const unsigned int setDimension1Value);
  void SetShapeColour(const Colour blockColorValue);
  // mutator functions for static members are static functions
  // this allows the static members to be changed before any
  // object of the class are created
  static void SetShapesCreated(unsigned int numberCreated);
  static void SetShapesExisting(unsigned int numberExisting);
  static void SetIfDebug(unsigned int ifDebugValue);

  // member function to plot a Shape to a bitmap
  // myImageValue is a bitmap
  virtual void Display(BMP &myImageValue, string theOutputFile) const = 0;
  virtual void Print() const = 0;
  virtual unsigned int Area() const = 0;
  virtual bool DoesOverlay(Shape *shape2) const = 0;

  // friend function
  // A friend function is not a member function but is
  // allowed to directly access the private members of the class
  friend ostream &operator<<(ostream &os, const Shape &myShape);
  const Shape &operator=(const Shape &shape2);
  virtual bool operator==(const Shape &shape2) const;
  virtual bool operator>(Shape &shape2) const = 0;
  virtual bool operator<(Shape &shape2) const = 0;

 protected:
  void CheckOffPage(string objectTypeName);
  void CheckXPartOffPage(string objectTypeName);
  virtual void CheckYPartOffPage() = 0;
  // static members counting the number of objects in this
  // class have been created by the application, and how
  // many objects of this class presently exist
  static unsigned int shapesCreated;
  static unsigned int shapesExisting;
  static unsigned int ifDebug;
  // Members expressing properties of a Shape
  unsigned int dimension1;
  unsigned int xLocation;
  unsigned int yLocation;
  Colour shapeColour;
};

#endif
