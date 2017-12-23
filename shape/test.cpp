#include <iostream>
#include "Gasket.h"
#include "Rectangle.h"
#include "Shape.h"
#include "Triangle.h"

using namespace std;

int main() {
  Triangle *p = new Triangle(0, 0, 100, Colour(0, 0, 0, 0));
  cout << ((p->isInRange(50, 100)) ? string("YES") : string("NO")) << endl;
  return 0;
}