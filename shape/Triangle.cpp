#include "Triangle.h"
#include <cmath>
#include "Gasket.h"
#include "Rectangle.h"

unsigned int Triangle::trianglesExisting = 0;
unsigned int Triangle::trianglesCreated = 0;
const double SQRT_3 = sqrt(3);
const string TriangleName = "Triangle";
static int calculateHeight(const int sideLength)
{
  return static_cast<unsigned int>((sideLength / 2) * SQRT_3);
}

static int calculateSideLength(const int height)
{
  return static_cast<unsigned int>((height / SQRT_3) * 2);
}

void Triangle::Display(BMP &myImageValue, string theOutputFile) const
{
  int yHeight = 0;
  double offset = 0;
  int t1 = 0;
  int t2 = 0;
  yHeight = static_cast<int>(dimension1 * sqrt(3.0) / 2.0);
  if (yLocation < 0 || yLocation > pageLength ||
      yLocation + yHeight > pageLength)
  {
    cerr << "point may be located outside of plotting page\n"
         << endl;
    return;
  }

  if (xLocation < 0 || xLocation >= pageWidth ||
      xLocation + dimension1 > pageWidth)
  {
    cerr << "point may be located outside of plotting page\n"
         << endl;
    return;
  }

  // each pixel within the Triangle must be Set to the correct colour
  // myImageValue(i,j) is pixel j in row i
  // each value in the Colour object is Set for each pixel in
  // the Triangle
  yHeight = static_cast<int>(dimension1 * sqrt(3.0) / 2.0);
  for (int j = yLocation; j < (yLocation + yHeight); j++)
  {
    offset = static_cast<double>(dimension1) / yHeight / 2.0;
    t1 = static_cast<int>(ceil((j - yLocation + 1) * offset));
    t2 = static_cast<int>(floor((j - yLocation + 1) * offset));
    for (int i = 0; i < dimension1; i++)
    {
      if (i < t1 || i > dimension1 - t2)
        continue;
      myImageValue(i + xLocation, j)->Red = shapeColour.GetRedNumber();
      myImageValue(i + xLocation, j)->Blue = shapeColour.GetBlueNumber();
      myImageValue(i + xLocation, j)->Green = shapeColour.GetGreenNumber();
      myImageValue(i + xLocation, j)->Alpha = shapeColour.GetAlphaNumber();
    }
  }

  // write generated bitmap image to a file
  myImageValue.WriteToFile(theOutputFile.c_str());
}

Triangle::Triangle() : Shape()
{
  ++trianglesCreated;
  ++trianglesExisting;
}
Triangle::Triangle(unsigned int xLocationValue, unsigned int yLocationValue,
                   unsigned int dimension1Value, Colour blockColourValue)
    : Shape(xLocationValue, yLocationValue, dimension1Value, blockColourValue)
{
  CheckOffPage(TriangleName);
  CheckXPartOffPage(TriangleName);
  CheckYPartOffPage();
  ++trianglesCreated;
  ++trianglesExisting;
}
Triangle::Triangle(unsigned int xLocationValue, unsigned int yLocationValue,
                   Colour blockColourValue)
    : Shape(xLocationValue, yLocationValue, blockColourValue)
{
  CheckOffPage(TriangleName);
  CheckXPartOffPage(TriangleName);
  CheckYPartOffPage();
  ++trianglesCreated;
  ++trianglesExisting;
}
Triangle::Triangle(const Triangle &toBeCopied) : Shape(toBeCopied)
{
  CheckOffPage(TriangleName);
  CheckXPartOffPage(TriangleName);
  CheckYPartOffPage();
  ++trianglesCreated;
  ++trianglesExisting;
}
Triangle::~Triangle()
{
  --trianglesExisting;
  cout << "running Triangle destruct" << endl;
}

unsigned int Triangle::GetHeight() const { return calculateHeight(dimension1); }
unsigned int Triangle::GetTrianglesCreated() { return trianglesCreated; }
unsigned int Triangle::GetTrianglesExisting() { return trianglesExisting; }

void Triangle::SetXLocation(const unsigned int xLocationValue)
{
  xLocation = xLocationValue;
  CheckOffPage(TriangleName);
  CheckXPartOffPage(TriangleName);
}

void Triangle::SetYLocation(const unsigned int yLocationValue)
{
  yLocation = yLocationValue;
  CheckOffPage(TriangleName);
  CheckYPartOffPage();
}

void Triangle::SetDimension1(const unsigned int SetDimension1Value)
{
  dimension1 = SetDimension1Value;
  CheckXPartOffPage(TriangleName);
  CheckYPartOffPage();
}

void Triangle::SetTrianglesCreated(unsigned int numberCreated)
{
  trianglesCreated = numberCreated;
}

void Triangle::SetTrianglesExisting(unsigned int numberExisting)
{
  trianglesExisting = numberExisting;
}

void Triangle::Print() const { cout << *this; }

unsigned int Triangle::Area() const { return dimension1 * GetHeight() / 2; }

bool Triangle::DoesOverlay(Shape *shape2) const
{
  if (auto p_rectangle = dynamic_cast<Rectangle *>(shape2))
  {
    return p_rectangle->isInRange(xLocation, yLocation) &&
           p_rectangle->isInRange(xLocation + dimension1, yLocation) &&
           p_rectangle->isInRange(xLocation + dimension1 / 2,
                                  yLocation + GetHeight());
  }
  else if (auto p_triangle = dynamic_cast<Triangle *>(shape2))
  {
    return p_triangle->isInRange(xLocation, yLocation) &&
           p_triangle->isInRange(xLocation + dimension1, yLocation) &&
           p_triangle->isInRange(xLocation + dimension1 / 2,
                                 yLocation + GetHeight());
  }
  else if (auto p_gasket = dynamic_cast<Gasket *>(shape2))
  {
    return p_gasket->isInRange(xLocation, yLocation) &&
           p_gasket->isInRange(xLocation + dimension1, yLocation) &&
           p_gasket->isInRange(xLocation + dimension1 / 2,
                               yLocation + GetHeight());
  }
  else
  {
    return false;
  }
}

void Triangle::TriangleDivide(Triangle *subTriangleList)
{
  unsigned int half_sideLength = dimension1 / 2;
  unsigned int x1, x2, x3, y1, y2, y3;
  x1 = xLocation;
  y1 = yLocation;
  x2 = xLocation + half_sideLength;
  y2 = yLocation;
  x3 = xLocation + half_sideLength / 2;
  y3 = yLocation + static_cast<int>(half_sideLength * SQRT_3);
  subTriangleList[0] = Triangle(x1, y1, half_sideLength, shapeColour);
  subTriangleList[1] = Triangle(x2, y2, half_sideLength, shapeColour);
  subTriangleList[2] = Triangle(x3, y3, half_sideLength, shapeColour);
}

ostream &operator<<(ostream &os, const Triangle &myTriangle)
{
  os << "Printing contents of the Triangle object" << endl;
  os << setw(20) << "x Location " << setw(9) << myTriangle.xLocation << endl;
  os << setw(20) << "y Location " << setw(9) << myTriangle.yLocation << endl;
  os << setw(20) << "side length " << setw(9) << myTriangle.dimension1 << endl;

  os << setw(20) << "Triangle colour " << setw(9) << myTriangle.shapeColour
     << endl;
  os << setw(20) << "Shapes created " << setw(9) << Shape::shapesCreated
     << endl;
  os << setw(20) << "Shapes existing " << setw(9) << Shape::shapesExisting
     << endl;
  os << setw(20) << "Triangles created " << setw(9)
     << Triangle::trianglesCreated << endl;
  os << setw(20) << "Triangles existing " << setw(9)
     << Triangle::trianglesExisting << endl;

  return os;
}

const Triangle &Triangle::operator=(const Triangle &Triangle2)
{
  Shape::operator=(Triangle2);
  CheckOffPage(TriangleName);
  CheckXPartOffPage(TriangleName);
  CheckYPartOffPage();
  return *this;
}

bool Triangle::operator==(const Shape &shape2) const
{
  if (auto p = dynamic_cast<const Triangle *>(&shape2))
  {
    return Shape::operator==(shape2);
  }
  else
  {
    return false;
  }
}

bool Triangle::operator>(Shape &shape2) const { return Area() > shape2.Area(); }

bool Triangle::operator<(Shape &shape2) const { return Area() < shape2.Area(); }

bool Triangle::isInRange(unsigned int xLocationValue,
                         unsigned int yLocationValue)
{
  int x, y;
  x = static_cast<int>(xLocationValue);
  y = static_cast<int>(yLocationValue);
  x = x - xLocation;
  y = y - yLocation;
  return x >= 0 && y >= 0 && y <= (SQRT_3 * x) &&
         y <= (SQRT_3 * (dimension1 - x));
}

void Triangle::CheckYPartOffPage()
{
  if (yLocation + GetHeight() > pageLength)
  {
    cout << "Triangle object partially off the page" << endl;
    cout << "ylocation is " << yLocation << endl;
    cout << "X dimension was " << dimension1 << " Y dimension was "
         << GetHeight() << endl;
    dimension1 = calculateSideLength(pageLength - yLocation);
    cout << "X dimension is " << dimension1 << " Y dimension is " << GetHeight()
         << endl;
  }
}
