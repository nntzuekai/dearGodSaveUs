#ifndef RectangleFlag
#define RectangleFlag

#include "Shape.h"

class Rectangle : public Shape
{
public:
  Rectangle();
  Rectangle(int xLocationValue, int yLocationValue, int Dimension1Value,
            int HeightValue, Colour blockColourValue);
  Rectangle(int xLocationValue, int yLocationValue, Colour blockColourValue);
  Rectangle(const Rectangle &toBeCopied);
  ~Rectangle();

  unsigned int GetHeight() const;
  static unsigned int GetRectanglesCreated();
  static unsigned int GetRectanglesExisting();

  void SetDimension1(const int widthValue);
  void SetHeight(const int heightValue);
  void SetXLocation(const int xLocationValue);
  void SetYLocation(const int yLocationValue);
  static void SetRectanglesCreated(int numberCreated);
  static void SetRectanglesExisting(int numberExisting);

  friend ostream &operator<<(ostream &os, const Rectangle &myRectangle);
  void Display(BMP &myImageValue, string theOutputFile) const;
  void Print() const;
  bool DoesOverlay(Shape *shape2) const;
  unsigned int Area() const;

  friend ostream &operator<<(ostream &os, const Rectangle &myRectangle);
  const Rectangle &operator=(const Rectangle &Rectangle2);
  bool operator==(const Shape &shape2) const;
  bool operator>(Shape &shape2) const;
  bool operator<(Shape &shape2) const;

  bool isInRange(unsigned int xLocationValue, unsigned int yLocationValue);

private:
  void CheckYPartOffPage();
  static unsigned int rectanglesCreated;
  static unsigned int rectanglesExisting;
  unsigned int height;
};

#endif
