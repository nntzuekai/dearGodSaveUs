#ifndef GasketFlag
#define GasketFlag

#include "Shape.h"
#include "Triangle.h"

class Gasket : public Shape
{
public:
  Gasket();
  Gasket(unsigned int iterationsValue, unsigned int xLocationValue,
         unsigned int yLocationValue, unsigned int dimension1Value,
         Colour blockColourValue);
  Gasket(const Gasket &toBeCopied);
  Gasket(unsigned int xLocationValue, unsigned int yLocationValue,
         Colour blockColourValue);
  ~Gasket();

  unsigned int GetHeight() const;
  unsigned int GetIterations() const;
  static unsigned int GetGasketCreated();
  static unsigned int GetGasketExisting();

  // mutator functions,
  void SetIterations(const unsigned int iterationsValue);
  void SetXLocation(const unsigned int xLocationValue);
  void SetYLocation(const unsigned int yLocationValue);
  void SetDimension1(const unsigned int setDimension1Value);
  static void SetGasketCreated(unsigned int numberCreated);
  static void SetGasketExisting(unsigned int numberExisting);

  void Display(BMP &myImageValue, string theOutputFile) const;
  void Print() const;
  unsigned int Area() const;
  bool DoesOverlay(Shape *shape2) const;

  friend ostream &operator<<(ostream &os, const Gasket &myGasket);
  const Gasket &operator=(const Gasket &Gasket2);
  bool operator==(const Shape &shape2) const;
  bool operator>(Shape &shape2) const;
  bool operator<(Shape &shape2) const;

  bool isInRange(unsigned int xLocationValue,
                 unsigned int yLocationValue) const;

private:
  void CheckYPartOffPage();
  void GasketDivide(Triangle *listOfSubTriangles,
                    unsigned int numTriangleToDivide);

  unsigned int iterations;

  Triangle *listOfSubTriangles;
  unsigned int lenSubTriList;
  static unsigned int gasketsCreated;
  static unsigned int gasketsExisting;
};

#endif
