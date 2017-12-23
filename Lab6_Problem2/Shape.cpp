/*
 * Author: Huang Ruikai
 */

#include "Shape.h"
#include "ShapeException.h"
#include <typeinfo>

using namespace std;

unsigned int Shape::shapesCreated=0;
unsigned int Shape::shapesExisting=0;
unsigned int Shape::ifDebug=0;

Shape::Shape():
    dimension1(100),
    xLocation(10),
    yLocation(10),
    shapeColour(0,0,0,255)
{
	++shapesCreated;
	++shapesExisting;
}

Shape::Shape(const Shape &toBeCopied):
    dimension1(toBeCopied.dimension1),
    xLocation(toBeCopied.xLocation),
    yLocation(toBeCopied.yLocation),
    shapeColour(toBeCopied.shapeColour),
    ifDebug(toBeCopied.ifDebug)
{
	++shapesCreated;
	++shapesExisting;
}

Shape::Shape(unsigned int xLocationValue, unsigned int yLocationValue, unsigned int dimension1Value, Colour blockColourValue, unsigned int ifDebug):
    dimension1(dimension1Value),
    xLocation(xLocationValue),
    yLocation(yLocationValue),
    shapeColour(blockColourValue),
    ifDebug(ifDebug)
{
	++shapesCreated;
	++shapesExisting;
}

Shape::Shape(unsigned int xLocationValue, unsigned int yLocationValue, Colour blockColourValue, unsigned int ifDebug):
    dimension1(100),
    xLocation(xLocationValue),
    yLocation(yLocationValue),
    shapeColour(blockColourValue),
    ifDebug(ifDebug)
{
	++shapesCreated;
	++shapesExisting;
}

Shape::~Shape()
{
	--shapesExisting;
}

unsigned int Shape::GetXLocation() const
{
	return xLocation;
}

unsigned int Shape::GetYLocation() const
{
	return yLocation;
}

unsigned int Shape::GetDimension1() const
{
	return dimension1;
}

Colour Shape::GetShapeColour() const
{
	return shapeColour;
}

unsigned int Shape::GetShapesCreated()
{
	return shapesCreated;
}

unsigned int Shape::GetShapesExisting()
{
	return shapesExisting;
}

void Shape::SetXLocation(const unsigned int xLocationValue)
{
	xLocation=xLocationValue;
}

void Shape::SetYLocation(const unsigned int yLocationValue)
{
	yLocation=yLocationValue;
}

void Shape::SetDimension1(const unsigned int setDimension1Value)
{
	dimension1=setDimension1Value;
}

void Shape::SetShapeColour(const Colour blockColorValue)
{
	shapeColour=blockColorValue;
}

void Shape::SetShapesCreated(unsigned int numberCreated)
{
	shapesCreated=numberCreated;
}

void Shape::SetShapesExisting(unsigned int numberExisting)
{
	shapesExisting=numberExisting;
}

ostream &operator <<(ostream &os, const Shape &myShape)
{
	cout << setw(20) << "Dimension1 " << setw(9) << myShape.dimension1 << '\n';
	cout << setw(20) << "xLocation " << setw(9) << myShape.xLocation << '\n';
	cout << setw(20) << "shapeColour " << setw(9) << myShape.shapeColour << '\n';
	cout << setw(20) << "Shapes created " << setw(9) << myShape.shapesCreated << '\n';
	cout << setw(20) << "Shapes existing " << setw(9) << myShape.shapesExisting << endl;
	return os;
}

const Shape &Shape::operator =(const Shape &shape2)
{
	dimension1=shape2.dimension1;
	xLocation=shape2.xLocation;
	yLocation=shape2.yLocation;
	shapeColour=shape2.shapeColour;

	return *this;
}

bool Shape::operator==(const Shape &shape2) const
{
	return typeid(*this)==typeid(shape2)&&
	        dimension1==shape2.dimension1&&
	        xLocation==shape2.xLocation&&
	        yLocation==shape2.yLocation&&
	        shapeColour==shape2.shapeColour;
}

/*
 * Check if (xLocation, yLocation) is off the page
 * If so, correct it by removing it to (0, 0)
 */
void Shape::CheckOffPage(string objectTypeName)
{
	if (xLocation > pageWidth || yLocation > pageLength) {
		switch (ifDebug) {
			case 2:{
				throw ShapeOffPageException(xLocation, yLocation);
				break;
			}
			case 1:
			{
				cerr << objectTypeName <<'\n';
				cerr << ShapeOffPageException::info<<'\n';
				cerr << "X position was "<<xLocation<<" Y position was "<<yLocation<<'\n';
				cerr << "X position and Y position have been reset to 0" << endl;
				xLocation = yLocation = 0;
				break;
			}
			default:{
				xLocation = yLocation = 0;
				break;
			}
		}
	}
}

/*
 * Check if the Shape extends off the page in X direction
 * If so, correct it by truncating dimension1
 */
void Shape::CheckXPartOffPage(string objectTypeName)
{
	if(xLocation+dimension1>pageWidth){
		switch (ifDebug) {
			case 2:{
				throw ShapeXPartOffPageException(xLocation,yLocation,dimension1,pageWidth-xLocation);
				break;
			}
			case 1:{
				cerr<<objectTypeName<<endl;
				cerr<<ShapeXPartOffPageException::info<<'\n';
				cerr<<"X position was "<<xLocation<<" Y position was "<<yLocation<<'\n';
				cerr<<"X dimension reset to include only the part of "<<objectTypeName<<" on the page\n";
				cerr<<"X dimension was "<<dimension1;
				dimension1=pageWidth-xLocation;
				cerr<<" X dimension is "<<dimension1<<endl;
				break;
			}
			default:{
				dimension1=pageWidth-xLocation;
				break;
			}
		}

	}
}
