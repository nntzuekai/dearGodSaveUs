#ifndef TriangleFlag
#define TriangleFlag

#include "Shape.h"

class Triangle : public Shape
{
public:
  Triangle();
  Triangle(unsigned int xLocationValue, unsigned int yLocationValue,
           unsigned int dimension1Value, Colour blockColourValue);
  Triangle(unsigned int xLocationValue, unsigned int yLocationValue,
           Colour blockColourValue);
  Triangle(const Triangle &toBeCopied);
  ~Triangle();

  unsigned int GetHeight() const;
  static unsigned int GetTrianglesCreated();
  static unsigned int GetTrianglesExisting();

  void SetXLocation(const unsigned int xLocationValue);
  void SetYLocation(const unsigned int yLocationValue);
  void SetDimension1(const unsigned int setDimension1Value);

  static void SetTrianglesCreated(unsigned int numberCreated);
  static void SetTrianglesExisting(unsigned int numberExisting);

  void Display(BMP &myImageValue, string theOutputFile) const;
  void Print() const;
  unsigned int Area() const;
  bool DoesOverlay(Shape *shape2) const;

  void TriangleDivide(Triangle *subTriangleList);

  friend ostream &operator<<(ostream &os, const Triangle &myTriangle);
  const Triangle &operator=(const Triangle &Triangle2);
  bool operator==(const Shape &shape2) const;
  bool operator>(Shape &shape2) const;
  bool operator<(Shape &shape2) const;

  bool isInRange(unsigned int xLocationValue, unsigned int yLocationValue);

private:
  void CheckYPartOffPage();
  static unsigned int trianglesCreated;
  static unsigned int trianglesExisting;
};

#endif
