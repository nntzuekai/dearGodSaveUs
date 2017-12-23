/*
 * Author: Huang Ruikai
 */

#include "Rectangle.h"
#include <typeinfo>
#include <stdexcept>
#include "ShapeException.h"

#define width dimension1
#define blockColour shapeColour

static string name_rectangle="Rectangle";//Name of object triangle
static string destrct="running Rectangle destruct";

using namespace std;

unsigned int Rectangle::rectanglesCreated=0;
unsigned int Rectangle::rectanglesExisting=0;

Rectangle::Rectangle():
    Shape()
{
	++rectanglesCreated;
	++rectanglesExisting;
}

Rectangle::Rectangle(unsigned int xLocationValue, unsigned int yLocationValue, unsigned int lengthValue, unsigned int HeightValue, Colour blockColourValue):
    Shape(xLocationValue,yLocationValue,lengthValue,blockColourValue),
    height(HeightValue)
{
	++rectanglesCreated;
	++rectanglesExisting;

	CheckOffPage(name_rectangle);
	CheckXPartOffPage(name_rectangle);
	CheckYPartOffPage();
}

Rectangle::Rectangle(unsigned int xLocationValue, unsigned int yLocationValue, Colour blockColourValue):
    Shape(xLocationValue,yLocationValue,100,blockColourValue),
    height(100)
{
	++rectanglesCreated;
	++rectanglesExisting;

	CheckOffPage(name_rectangle);
	CheckXPartOffPage(name_rectangle);
	CheckYPartOffPage();
}

Rectangle::Rectangle(const Rectangle &toBeCopied):
    Shape(toBeCopied),
    height(toBeCopied.height)
{
	++rectanglesCreated;
	++rectanglesExisting;
}

Rectangle::~Rectangle()
{
	--rectanglesExisting;
	cout<<destrct<<endl;
}

Colour Rectangle::GetBlockColour() const
{
	return shapeColour;
}

unsigned int Rectangle::GetWidth() const
{
	return width;
}

unsigned int Rectangle::GetHeight() const
{
	return height;
}

void Rectangle::SetColour(const Colour blockColourValue)
{
	shapeColour=blockColourValue;
}

unsigned int Rectangle::GetRectanglesCreated()
{
	return rectanglesCreated;
}

unsigned int Rectangle::GetRectanglesExisting()
{
	return rectanglesExisting;
}

void Rectangle::SetXLocation(const unsigned int xLocationValue)
{
	xLocation=xLocationValue;
	CheckOffPage(name_rectangle);
	CheckXPartOffPage(name_rectangle);
}

void Rectangle::SetDimension1(const unsigned int widthValue)
{
	SetWidth(widthValue);
}

void Rectangle::SetYLocation(const unsigned int yLocationValue)
{
	yLocation=yLocationValue;
	CheckOffPage(name_rectangle);
	CheckYPartOffPage();
}

void Rectangle::SetWidth(const unsigned int widthValue)
{
	width=widthValue;
	CheckXPartOffPage(name_rectangle);
}

void Rectangle::SetHeight(const unsigned int heightValue)
{
	height=heightValue;
	CheckYPartOffPage();
}

void Rectangle::SetRectanglesCreated(unsigned int numberCreated)
{
	rectanglesCreated=numberCreated;
}

void Rectangle::SetRectanglesExisting(unsigned int numberExisting)
{
	rectanglesExisting=numberExisting;
}

/*
 * if two rectangles intersect
 */
bool Rectangle::DoesIntersect(const Rectangle &rectangle2)
{
	const Rectangle *left = nullptr, *right = nullptr;
	if(xLocation <= rectangle2.xLocation) {
		left = this;
		right = &rectangle2;
	}
	else {
		left = &rectangle2;
		right = this;
	}

	if(right->xLocation > left->xLocation + left-> width ) {//Seperate in X dimension
		return false;
	}
	if(left->yLocation <= right->yLocation) {
		//upper left and lower right
		return right->yLocation <= left->yLocation + left->height;
	}
	else {//lower left and upper right
		return left->yLocation <= right->yLocation + right->height;
	}
}

const Rectangle &Rectangle::operator =(const Rectangle &Rectangle2)
{
	this->Shape::operator =(Rectangle2);//base part
	height=Rectangle2.height;

	return *this;
}

bool Rectangle::operator==(const Shape &Shape2) const
{
	if(auto rec=dynamic_cast<const Rectangle*>(&Shape2)){
		return this->Shape::operator ==(Shape2)&&//Base part
		        height==rec->height;
	}
	else{
		return false;
	}
}

ostream &operator <<(ostream &os, const Rectangle &myRectangle)
{
	cout<<"Printing contents of the Rectangle Object"<<endl;
	cout<<setw(20)<<"length " <<setw(9)<<myRectangle.dimension1<<'\n';
	cout<<setw(20)<<"height " <<setw(9)<<myRectangle.height<<'\n';
	cout<<setw(20)<<"x location " <<setw(9)<<myRectangle.xLocation<<'\n';
	cout<<setw(20)<<"y location " <<setw(9)<<myRectangle.yLocation<<'\n';
	cout<<setw(20)<<"Rectangle Colour " <<setw(9)<<myRectangle.blockColour<<'\n';
	cout<<setw(20)<<"Shapes Created " <<setw(9)<<myRectangle.shapesCreated<<'\n';
	cout<<setw(20)<<"ShapesExisting " <<setw(9)<<myRectangle.shapesExisting<<'\n';
	cout<<setw(20)<<"Rectangles Created " <<setw(9)<<myRectangle.rectanglesCreated<<'\n';
	cout<<setw(20)<<"Rectangles Existing " <<setw(9)<<myRectangle.rectanglesExisting<<endl;

	return os;
}

void Rectangle::Display(BMP &myImageValue, string theOutputFile) const
{
	unsigned int i;
	unsigned int j;

	if(yLocation >= pageLength ||
	        yLocation + height > pageLength) {
		cerr << "point may be located outside of plotting page\n"
		     << endl;
		return;
	}

	if(xLocation >= pageWidth ||
	        xLocation + width  > pageWidth ) {
		cerr << "point may be located outside of plotting page\n"
		     << endl;
		return;
	}

	// each pixel within the rectangle must be Set to the correct colour
	// myImageValue(i,j) is pixel j in row i
	// each value in the Colour object is Set for each pixel in
	// the Rectangle
	for(j = yLocation; j < (yLocation + height); j++) {
		for (i = xLocation; i < (xLocation + width); i++) {
			myImageValue(i, j)->Red = blockColour.GetRedNumber();
			myImageValue(i, j)->Blue = blockColour.GetBlueNumber();
			myImageValue(i, j)->Green = blockColour.GetGreenNumber();
			myImageValue(i, j)->Alpha = blockColour.GetAlphaNumber();
		}
	}

	//write generated bitmap image to a file
	myImageValue.WriteToFile(theOutputFile.c_str() );

}

void Rectangle::Print() const
{
	cout<<*this;
}

unsigned int Rectangle::Area() const
{
	return height*width;
}

bool Rectangle::DoesOverlay(Shape *shape2) const
{
	if(auto rec=dynamic_cast<Rectangle*>(shape2)){//Is a rectangle
		return (xLocation>=rec->xLocation)&&
		        (yLocation>=rec->yLocation)&&
		        (xLocation+width<=rec->xLocation+rec->width)&&
		        (yLocation+height<=rec->yLocation+rec->height);
	}
	else if(auto tri=dynamic_cast<Triangle*>(shape2)){//is a triangle
		//containing upper left, lower left and lower right points means containing the whole rectangle
		return tri->contains(xLocation,yLocation+height)&&
		        tri->contains(xLocation+width,yLocation+height)&&
		        (yLocation>=tri->GetYLocation());
	}
	else if(auto gas=dynamic_cast<Gasket*>(shape2)){//is a gasket
		//Same logic as shape2 is a triangle
		return gas->contains(xLocation,yLocation+height)&&
		        gas->contains(xLocation+width,yLocation+height)&&
		        (yLocation>=gas->GetYLocation());
	}
	else{
		throw runtime_error("Ill pointer to shape");
	}
}

Rectangle *Rectangle::clone() const
{
	return new Rectangle(*this);
}

bool Rectangle::operator >(Shape &shape2) const
{
	return Area()>shape2.Area();
}

bool Rectangle::operator <(Shape &shape2) const
{
	return Area()<shape2.Area();
}

/*
 * Check if the Shape extends off the page in Y direction
 * If so, correct it by truncating height
 */
void Rectangle::CheckYPartOffPage()
{
	if(yLocation+height>pageLength){
		switch (ifDebug) {
			case 2:{
				throw ShapeYPartOffPageException(xLocation, yLocation, dimension1, dimension1, height, pageLength-yLocation);
				break;
			}
			case 1:{
				cerr<<"Rectangle\n";
				cout<<ShapeYPartOffPageException::info<<'\n';
				cerr<<"X position was "<<xLocation<<" Y position was "<<yLocation<<'\n';
				cerr<<"X dimension was "<<dimension1<<" Y dimension was "<<height<<'\n';
				cerr<<"Dimensions reset to include only the part of rectangle on the page\n";
				height=pageLength-yLocation;
				cerr<<"X dimension is "<<dimension1<<" Y dimension is "<<height<<endl;
				break;
			}
			default:{
				height=pageLength-yLocation;
				break;
			}
		}
	}
}

#undef width
#undef blockColour
