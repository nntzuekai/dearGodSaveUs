#include "Gasket.h"
#include "Rectangle.h"

unsigned int Gasket::gasketsCreated = 0;
unsigned int Gasket::gasketsExisting = 0;

const double SQRT_3 = sqrt(3);
const string GasketName = "Gasket";
static int calculateHeight(const int sideLength)
{
  return static_cast<int>((sideLength / 2) * SQRT_3);
}

static int calculateSideLength(const int height)
{
  return static_cast<int>((height / SQRT_3) * 2);
}

Gasket::Gasket() : Shape(), iterations(0)
{
  lenSubTriList = 1;
  listOfSubTriangles = new Triangle[lenSubTriList];
  listOfSubTriangles[0] =
      Triangle(xLocation, yLocation, dimension1, shapeColour);
  gasketsCreated++;
  gasketsExisting++;
}

Gasket::Gasket(unsigned int iterationsValue, unsigned int xLocationValue,
               unsigned int yLocationValue, unsigned int dimension1Value,
               Colour blockColourValue)
    : Shape(xLocationValue, yLocationValue, dimension1Value, blockColourValue),
      iterations(iterationsValue)
{
  CheckOffPage(GasketName);
  CheckXPartOffPage(GasketName);
  CheckYPartOffPage();
  lenSubTriList = static_cast<unsigned int>(pow(3, iterations));
  listOfSubTriangles = new Triangle[lenSubTriList];
  listOfSubTriangles[0] =
      Triangle(xLocation, yLocation, dimension1, shapeColour);
  for (size_t i = 0; i < iterations; ++i)
  {
    unsigned int numTriangleToDivide = static_cast<unsigned int>(pow(3, i));
    GasketDivide(listOfSubTriangles, numTriangleToDivide);
  }
  gasketsCreated++;
  gasketsExisting++;
}

Gasket::Gasket(const Gasket &toBeCopied)
    : Shape(toBeCopied), iterations(toBeCopied.iterations)
{
  CheckOffPage(GasketName);
  CheckXPartOffPage(GasketName);
  CheckYPartOffPage();
  lenSubTriList = static_cast<unsigned int>(pow(3, iterations));
  listOfSubTriangles = new Triangle[lenSubTriList];
  listOfSubTriangles[0] =
      Triangle(xLocation, yLocation, dimension1, shapeColour);
  for (size_t i = 0; i < iterations; ++i)
  {
    unsigned int numTriangleToDivide = static_cast<unsigned int>(pow(3, i));
    GasketDivide(listOfSubTriangles, numTriangleToDivide);
  }
  gasketsCreated++;
  gasketsExisting++;
}

Gasket::Gasket(unsigned int xLocationValue, unsigned int yLocationValue,
               Colour blockColourValue)
    : Shape(xLocationValue, yLocationValue, blockColourValue), iterations(0)
{
  CheckOffPage(GasketName);
  CheckXPartOffPage(GasketName);
  CheckYPartOffPage();
  lenSubTriList = 1;
  listOfSubTriangles = new Triangle[lenSubTriList];
  listOfSubTriangles[0] =
      Triangle(xLocation, yLocation, dimension1, shapeColour);
  gasketsCreated++;
  gasketsExisting++;
}

Gasket::~Gasket()
{
  cout << "running Gasket destruct" << endl;
  delete[] listOfSubTriangles;
  --gasketsExisting;
}
unsigned int Gasket::GetHeight() const { return calculateHeight(dimension1); }
unsigned int Gasket::GetIterations() const { return iterations; }

unsigned int Gasket::GetGasketCreated() { return gasketsCreated; }
unsigned int Gasket::GetGasketExisting() { return gasketsExisting; }

void Gasket::SetIterations(const unsigned int iterationsValue)
{
  Triangle *newListOfSubTriangles = nullptr;
  for (size_t i = iterations; i < iterationsValue; ++i)
  {
    newListOfSubTriangles = new Triangle[lenSubTriList * 3];
    GasketDivide(newListOfSubTriangles, lenSubTriList);
    lenSubTriList *= 3;
  }
  iterations = iterationsValue;
}

void Gasket::SetXLocation(const unsigned int xLocationValue)
{
  Shape::SetXLocation(xLocationValue);
  CheckOffPage(GasketName);
  CheckXPartOffPage(GasketName);
  delete[] listOfSubTriangles;
  lenSubTriList = 1;
  listOfSubTriangles = new Triangle[1];
  listOfSubTriangles[0] =
      Triangle(xLocation, yLocation, dimension1, shapeColour);

  Triangle *newListOfSubTriangles = nullptr;
  for (size_t i = 0; i < iterations; ++i)
  {
    newListOfSubTriangles = new Triangle[lenSubTriList * 3];
    GasketDivide(newListOfSubTriangles, lenSubTriList);
    lenSubTriList *= 3;
  }
}

void Gasket::SetYLocation(const unsigned int yLocationValue)
{
  Shape::SetYLocation(yLocationValue);
  CheckOffPage(GasketName);
  CheckYPartOffPage();
  delete[] listOfSubTriangles;
  lenSubTriList = 1;
  listOfSubTriangles = new Triangle[1];
  listOfSubTriangles[0] =
      Triangle(xLocation, yLocation, dimension1, shapeColour);

  Triangle *newListOfSubTriangles = nullptr;
  for (size_t i = 0; i < iterations; ++i)
  {
    newListOfSubTriangles = new Triangle[lenSubTriList * 3];
    GasketDivide(newListOfSubTriangles, lenSubTriList);
    lenSubTriList *= 3;
  }
}

void Gasket::SetDimension1(const unsigned int sideLengthValue)
{
  CheckXPartOffPage(GasketName);
  CheckYPartOffPage();

  delete[] listOfSubTriangles;
  lenSubTriList = 1;
  listOfSubTriangles = new Triangle[1];
  listOfSubTriangles[0] =
      Triangle(xLocation, yLocation, dimension1, shapeColour);

  Triangle *newListOfSubTriangles = nullptr;
  for (int i = 0; i < iterations; ++i)
  {
    newListOfSubTriangles = new Triangle[lenSubTriList * 3];
    GasketDivide(newListOfSubTriangles, lenSubTriList);
    lenSubTriList *= 3;
  }
}

void Gasket::SetGasketCreated(unsigned int numberCreated)
{
  gasketsCreated = numberCreated;
}

void Gasket::SetGasketExisting(unsigned int numberExisting)
{
  gasketsExisting = numberExisting;
}

void Gasket::Display(BMP &myImageValue, string theOutputFile) const
{
  for (size_t i = 0; i < lenSubTriList; ++i)
  {
    Triangle &tri = listOfSubTriangles[i];
    tri.Display(myImageValue, theOutputFile);
  }
}

void Gasket::Print() const { cout << *this; }

unsigned int Gasket::Area() const { return dimension1 * GetHeight() / 2; }

bool Gasket::DoesOverlay(Shape *shape2) const
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

ostream &operator<<(ostream &os, const Gasket &myGasket)
{
  os << "Printing contents of the Gasket object" << endl;
  os << setw(20) << "iterations" << setw(9) << myGasket.iterations;
  os << setw(20) << "x location" << setw(9) << myGasket.xLocation << endl;
  os << setw(20) << "y location" << setw(9) << myGasket.yLocation << endl;
  os << setw(20) << "side length" << setw(9) << myGasket.dimension1 << endl;
  os << setw(20) << "Gasket colour" << setw(9) << myGasket.shapeColour << endl;
  os << setw(20) << "lenSubTriList" << setw(9) << myGasket.lenSubTriList
     << endl;
  os << setw(20) << "Shapes created" << setw(9) << Shape::shapesCreated << endl;
  os << setw(20) << "Shapes existing" << setw(9) << Shape::shapesExisting
     << endl;
  os << setw(20) << "Gaskets created" << setw(9) << Gasket::gasketsCreated
     << endl;
  os << setw(20) << "Gaskets existing" << setw(9) << Gasket::gasketsExisting
     << endl;
  os << endl;
  for (size_t i = myGasket.lenSubTriList - 1; i >= 0; --i)
  {
    os << myGasket.listOfSubTriangles[i];
    os << endl;
  }
  return os;
}

const Gasket &Gasket::operator=(const Gasket &Gasket2)
{
  Shape::operator=(Gasket2);
  iterations = Gasket2.iterations;
  lenSubTriList = Gasket2.lenSubTriList;
  delete[] listOfSubTriangles;
  listOfSubTriangles = new Triangle[lenSubTriList];
  for (size_t i = 0; i < lenSubTriList; ++i)
  {
    listOfSubTriangles[i] = Triangle(Gasket2.listOfSubTriangles[i]);
  }
  return *this;
}

bool Gasket::operator==(const Shape &shape2) const
{
  if (auto p = dynamic_cast<const Gasket *>(&shape2))
  {
    if (Shape::operator==(shape2) == false)
    {
      return false;
    }
    if (iterations != p->iterations || lenSubTriList != p->lenSubTriList)
    {
      return false;
    }
    for (size_t i = 0; i < lenSubTriList; ++i)
    {
      if (!(listOfSubTriangles[i] == p->listOfSubTriangles[i]))
      {
        return false;
      }
    }
    return true;
  }
  else
  {
    return false;
  }
}

bool Gasket::operator>(Shape &shape2) const { return Area() > shape2.Area(); }

bool Gasket::operator<(Shape &shape2) const { return Area() < shape2.Area(); }

bool Gasket::isInRange(unsigned int xLocationValue,
                       unsigned int yLocationValue) const
{
  int x, y;
  x = static_cast<int>(xLocationValue);
  y = static_cast<int>(yLocationValue);
  x = x - xLocation;
  y = y - yLocation;
  return x >= 0 && y >= 0 && y <= (SQRT_3 * x) &&
         y <= (SQRT_3 * (dimension1 - x));
}

void Gasket::GasketDivide(Triangle *newListOfSubTriangles,
                          unsigned int numTriangleToDivide)
{
  for (size_t i = 0; i < numTriangleToDivide; ++i)
  {
    Triangle &tri = listOfSubTriangles[i];
    tri.TriangleDivide(newListOfSubTriangles + i * 3);
  }
  delete[] listOfSubTriangles;
  listOfSubTriangles = newListOfSubTriangles;
}

void Gasket::CheckYPartOffPage()
{
  if (yLocation + GetHeight() > pageLength)
  {
    cout << "Gasket object partially off the page" << endl;
    cout << "ylocation is " << yLocation << endl;
    cout << "X dimension was " << dimension1 << " Y dimension was "
         << GetHeight() << endl;
    dimension1 = calculateSideLength(pageLength - yLocation);
    cout << "X dimension is " << dimension1 << " Y dimension is " << GetHeight()
         << endl;
  }
}