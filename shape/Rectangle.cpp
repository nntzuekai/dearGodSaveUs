#include "Rectangle.h"
#include "Gasket.h"
#include "Triangle.h"
unsigned int Rectangle::rectanglesExisting = 0;
unsigned int Rectangle::rectanglesCreated = 0;
const string RectangleName = "Rectangle";

void Rectangle::Display(BMP &myImageValue, string theOutputFile) const
{
  int i;
  int j;

  if (yLocation >= pageLength || yLocation + height > pageLength)
  {
    cerr << "point may be located outside of plotting page\n"
         << endl;
    return;
  }

  if (xLocation >= pageWidth || xLocation + dimension1 > pageWidth)
  {
    cerr << "point may be located outside of plotting page\n"
         << endl;
    return;
  }

  // each pixel within the rectangle must be Set to the correct colour
  // myImageValue(i,j) is pixel j in row i
  // each value in the Colour object is Set for each pixel in
  // the Rectangle
  for (j = yLocation; j < (yLocation + height); j++)
  {
    for (i = xLocation; i < (xLocation + dimension1); i++)
    {
      myImageValue(i, j)->Red = shapeColour.GetRedNumber();
      myImageValue(i, j)->Blue = shapeColour.GetBlueNumber();
      myImageValue(i, j)->Green = shapeColour.GetGreenNumber();
      myImageValue(i, j)->Alpha = shapeColour.GetAlphaNumber();
    }
  }

  // write generated bitmap image to a file
  myImageValue.WriteToFile(theOutputFile.c_str());
}

Rectangle::Rectangle() : Shape(), height(100)
{
  ++rectanglesCreated;
  ++rectanglesExisting;
}

Rectangle::Rectangle(int xLocationValue, int yLocationValue,
                     int dimension1Value, int heightValue,
                     Colour blockColourValue)
    : Shape(xLocationValue, yLocationValue, dimension1Value, blockColourValue),
      height(heightValue)
{
  CheckOffPage(RectangleName);
  CheckXPartOffPage(RectangleName);
  CheckYPartOffPage();
  ++rectanglesCreated;
  ++rectanglesExisting;
}

Rectangle::Rectangle(int xLocationValue, int yLocationValue,
                     Colour blockColourValue)
    : Shape(xLocationValue, yLocationValue, blockColourValue), height(100)
{
  CheckOffPage(RectangleName);
  CheckXPartOffPage(RectangleName);
  CheckYPartOffPage();
  ++rectanglesCreated;
  ++rectanglesExisting;
}

Rectangle::Rectangle(const Rectangle &toBeCopied)
    : Shape(toBeCopied), height(toBeCopied.height)
{
  CheckOffPage(RectangleName);
  CheckXPartOffPage(RectangleName);
  CheckYPartOffPage();
  ++rectanglesCreated;
  ++rectanglesExisting;
}

Rectangle::~Rectangle()
{
  --rectanglesExisting;
  cout << "running Rectangle destruct" << endl;
}

unsigned int Rectangle::GetHeight() const { return height; }

unsigned int Rectangle::GetRectanglesCreated() { return rectanglesCreated; }

unsigned int Rectangle::GetRectanglesExisting() { return rectanglesExisting; }

void Rectangle::SetDimension1(const int widthValue)
{
  dimension1 = widthValue;
  CheckXPartOffPage(RectangleName);
}

void Rectangle::SetHeight(const int heightValue)
{
  height = heightValue;
  CheckYPartOffPage();
}
void Rectangle::SetXLocation(const int xLocationValue)
{
  xLocation = xLocationValue;
  CheckOffPage(RectangleName);
  CheckXPartOffPage(RectangleName);
}
void Rectangle::SetYLocation(const int yLocationValue)
{
  yLocation = yLocationValue;
  CheckOffPage(RectangleName);
  CheckYPartOffPage();
}

void Rectangle::SetRectanglesCreated(int numberCreated)
{
  if (numberCreated >= 0)
  {
    rectanglesCreated = numberCreated;
  }
}

void Rectangle::SetRectanglesExisting(int numberExisting)
{
  if (numberExisting >= 0)
  {
    rectanglesExisting = numberExisting;
  }
}

ostream &operator<<(ostream &os, const Rectangle &myRectangle)
{
  os << "Printing contents of the Rectangle Object" << endl;
  os << setw(20) << "length " << setw(9) << myRectangle.dimension1 << endl;
  os << setw(20) << "height " << setw(9) << myRectangle.height << endl;
  os << setw(20) << "x location " << setw(9) << myRectangle.xLocation << endl;
  os << setw(20) << "y location " << setw(9) << myRectangle.yLocation << endl;
  os << setw(20) << "Rectangle Colour " << setw(9) << myRectangle.shapeColour
     << endl;
  os << setw(20) << "Shapes Created " << setw(9) << Shape::shapesCreated
     << endl;
  os << setw(20) << "Shapes Existing " << setw(9) << Shape::shapesExisting
     << endl;
  os << setw(20) << "Rectangles Created " << setw(9)
     << Rectangle::rectanglesCreated << endl;
  os << setw(20) << "Rectangles Existing " << setw(9)
     << Rectangle::rectanglesExisting << endl;

  return os;
}

void Rectangle::Print() const { cout << *this; }

const Rectangle &Rectangle::operator=(const Rectangle &Rectangle2)
{
  Shape::operator=(Rectangle2);
  height = Rectangle2.height;
  CheckOffPage(RectangleName);
  CheckXPartOffPage(RectangleName);
  CheckYPartOffPage();
  return *this;
}

bool Rectangle::operator==(const Shape &shape2) const
{
  if (auto p = dynamic_cast<const Rectangle *>(&shape2))
  {
    return Shape::operator==(shape2) && height == p->height;
  }
  else
  {
    return false;
  }
}

bool Rectangle::operator>(Shape &shape2) const
{
  return Area() > shape2.Area();
}

bool Rectangle::operator<(Shape &shape2) const
{
  return Area() < shape2.Area();
}

unsigned int Rectangle::Area() const { return dimension1 * height; }

bool Rectangle::DoesOverlay(Shape *shape2) const
{
  if (auto p_rectangle = dynamic_cast<Rectangle *>(shape2))
  {
    return p_rectangle->isInRange(xLocation, yLocation) &&
           p_rectangle->isInRange(xLocation + dimension1, yLocation) &&
           p_rectangle->isInRange(xLocation, yLocation + height) &&
           p_rectangle->isInRange(xLocation + dimension1, yLocation + height);
  }
  else if (auto p_triangle = dynamic_cast<Triangle *>(shape2))
  {
    return p_triangle->isInRange(xLocation, yLocation) &&
           p_triangle->isInRange(xLocation + dimension1, yLocation) &&
           p_triangle->isInRange(xLocation, yLocation + height) &&
           p_triangle->isInRange(xLocation + dimension1, yLocation + height);
  }
  else if (auto p_gasket = dynamic_cast<Gasket *>(shape2))
  {
    return p_gasket->isInRange(xLocation, yLocation) &&
           p_gasket->isInRange(xLocation + dimension1, yLocation) &&
           p_gasket->isInRange(xLocation, yLocation + height) &&
           p_gasket->isInRange(xLocation + dimension1, yLocation + height);
  }
  else
  {
    return false;
  }
}

void Rectangle::CheckYPartOffPage()
{
  if (yLocation + height > pageLength)
  {
    cout << "Rectangle object partially off the page" << endl;
    cout << "Y dimension reset to include only the part of rectangle on "
            "the page"
         << endl;
    cout << "Y dimension was " << height;
    height = pageLength - yLocation;
    cout << " Y dimension is " << height << endl;
  }
}

bool Rectangle::isInRange(unsigned int xLocationValue,
                          unsigned int yLocationValue)
{
  return xLocationValue >= xLocation &&
         xLocationValue <= xLocation + dimension1 &&
         yLocationValue >= yLocation && yLocationValue <= yLocation + height;
}