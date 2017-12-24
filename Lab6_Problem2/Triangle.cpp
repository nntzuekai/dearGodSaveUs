/*
 * Author: Huang Ruikai
 */

#include "Triangle.h"
#include "Rectangle.h"
#include "Gasket.h"
#include <typeinfo>
#include <stdexcept>
#include "ShapeException.h"

#define sideLength dimension1
#define triangColour shapeColour

static const string destrct="running Triangle destruct";
static const string name_triangle= "Triangle";//Name of object triangle

static constexpr double sqrt_3=sqrt(3.0);
static constexpr double sin60=sqrt_3/2.0;//Height = SideLength * sin(60 deg)

using namespace std;

int Triangle::trianglesCreated=0;
int Triangle::trianglesExisting=0;

Triangle::Triangle():
    Shape()
{
	++trianglesCreated;
	++trianglesExisting;
}

Triangle::Triangle(unsigned int xLocationValue, unsigned int yLocationValue, unsigned int sideLengthValue, Colour blockColourValue):
    Shape(xLocationValue,yLocationValue,sideLengthValue,blockColourValue)
{
	++trianglesCreated;
	++trianglesExisting;

	try{
		CheckOffPage(name_triangle);
		CheckXPartOffPage(name_triangle);
		CheckYPartOffPage();
	}catch(...){
		cerr<<"Called from Triangle Constructor 4 arguments"<<endl;
		throw;
	}
}

Triangle::Triangle(unsigned int xLocationValue, unsigned int yLocationValue, Colour blockColourValue):
    Shape(xLocationValue,yLocationValue,blockColourValue)
{
	++trianglesCreated;
	++trianglesExisting;

	try{
		CheckOffPage(name_triangle);
		CheckXPartOffPage(name_triangle);
		CheckYPartOffPage();
	}catch(...){
		cerr<<"Called from Triangle Constructor 3 arguments"<<endl;
		throw;
	}
}

Triangle::Triangle(const Triangle &toBeCopied):
    Shape(toBeCopied)
{
	++trianglesCreated;
	++trianglesExisting;
}

Triangle::~Triangle()
{
	--trianglesExisting;
	cout<<destrct<<endl;
}

unsigned int Triangle::GetTrianglesCreated()
{
	return trianglesCreated;
}

unsigned int Triangle::GetTrianglesExisting()
{
	return trianglesExisting;
}

/*
 * Height vertically from the bottom vertex to upper side
 * Height = SideLength * sin(60 deg)
 */
unsigned int Triangle::GetHeight() const
{
	return static_cast<unsigned int> (round(sideLength*sin60));
}

/*
 * Set and Check both in X and Y dimensions
 */
void Triangle::SetSideLength(const unsigned int setSideLengthValue)
{
	sideLength=setSideLengthValue;

	try{
		CheckXPartOffPage(name_triangle);
		CheckYPartOffPage();
	}catch(...){
		cerr<<"Called from Triangle SetSideLength"<<endl;
		throw;
	}
}

/*
 * simply call SetSideLength
 */
void Triangle::SetDimension1(const unsigned int setSideLengthValue)
{
	SetSideLength(setSideLengthValue);
}

void Triangle::SetXLocation(const unsigned int xLocationValue)
{
	xLocation=xLocationValue;
	try{
		CheckOffPage(name_triangle);
		CheckXPartOffPage(name_triangle);
	}catch(...){
		cerr<<"Called from Triangle SetXLocation"<<endl;
		throw;
	}
}

void Triangle::SetYLocation(const unsigned int yLocationValue)
{
	yLocation=yLocationValue;
	try{
		CheckOffPage(name_triangle);
		CheckYPartOffPage();
	}catch(...){
		cerr<<"Called from Triangle SetYLocation"<<endl;
		throw;
	}
}

void Triangle::SetTrianglesCreated(unsigned int numberCreated)
{
	trianglesCreated=numberCreated;
}

void Triangle::SetTrianglesExisting(unsigned int numberExisting)
{
	trianglesExisting=numberExisting;
}

void Triangle::TriangleDivide(Triangle *subTriangleList) const
{
	if(subTriangleList==nullptr){
		return;
	}

	auto new_l = sideLength / 2;//length of divided triangles
	subTriangleList[0] = {xLocation, yLocation, new_l, triangColour};
	subTriangleList[1] = {xLocation + new_l, yLocation, new_l, triangColour};
	subTriangleList[2] = {xLocation + sideLength / 4, static_cast<unsigned int> (round(yLocation + new_l * sin60)), new_l, triangColour};
}

const Triangle &Triangle::operator =(const Triangle &Triangle2)
{
	this->Shape::operator =(Triangle2);//Assign the part of Shape
	return *this;
}

bool Triangle::operator==(const Shape &shape2) const
{
	if(dynamic_cast<const Triangle*> (&shape2)){//shape2 is a triangle
		return this->Shape::operator ==(shape2);//same parts of Shape
	}
	else{//incompatible types
		return false;
	}
}

bool Triangle::operator >(Shape &shape2) const
{
	return Area() > shape2.Area();
}

bool Triangle::operator <(Shape &shape2) const
{
	return Area() < shape2.Area();
}

void Triangle::Print() const
{
	cout<<*this;
}

/*
 * Area = sqrt(3) * SideLength^2 / 4
 */
unsigned int Triangle::Area() const
{
	return static_cast<unsigned int>(lround(sqrt_3*sideLength*sideLength/4.0));
}

/*
 * If this is completely contained in shape2
 */
bool Triangle::DoesOverlay(Shape *shape2) const
{
	if(auto rec=dynamic_cast<Rectangle*>(shape2)){//Is a rectangle
		return (xLocation>=rec->GetXLocation())&&(xLocation<=rec->GetXLocation()+rec->GetWidth())&&
		        (yLocation>=rec->GetXLocation())&&(yLocation<=rec->GetYLocation()+rec->GetHeight())&&//(x, y) shouble be in rectangle
		        (xLocation+sideLength<=rec->GetXLocation()+rec->GetWidth())&&//inside in X dimension
		        (yLocation+GetHeight()<=rec->GetYLocation()+rec->GetHeight());//inside in Y dimension
	}
	if(auto tri=dynamic_cast<Triangle*>(shape2)){//is a triangle
		return tri->contains(xLocation,yLocation)&&//All three vertices should be in shape2
		        tri->contains(xLocation+sideLength,yLocation)&&
		        tri->contains(lround(xLocation+sideLength/2),yLocation+GetHeight());
	}

	else if(auto gas=dynamic_cast<Gasket*>(shape2)){//is a gasket
		return gas->contains(xLocation,yLocation)&& //All three vertices should be in shape2
		        gas->contains(xLocation+sideLength,yLocation)&&
		        gas->contains(lround(xLocation+sideLength/2),yLocation+GetHeight());
	}

	else{//Unrecognized type
		throw runtime_error("Ill pointer to shape");
	}
}

void Triangle::Display(BMP &myImageValue, string theOutputFile) const
{
	unsigned int yHeight = 0;
	double offset = 0;
	unsigned int t1 = 0;
	unsigned int t2 = 0;
	yHeight = static_cast<int> (sideLength * sqrt(3.0) / 2.0 );
	if(yLocation > pageLength || yLocation + yHeight > pageLength) {
		cerr << "point may be located outside of plotting page\n"
		     << endl;
		return;
	}

	if(xLocation >= pageWidth || xLocation + sideLength > pageWidth ) {
		cerr << "point may be located outside of plotting page\n"
		     << endl;
		return;
	}

	// each pixel within the Triangle must be Set to the correct colour
	// myImageValue(i,j) is pixel j in row i
	// each value in the Colour object is Set for each pixel in
	// the Triangle
	yHeight = static_cast<unsigned int> (sideLength * sqrt(3.0) / 2.0 );
	for(auto j = yLocation; j < (yLocation + yHeight); j++) {
		offset = static_cast<double>(sideLength) / yHeight / 2.0;
		t1 = static_cast<int>( ceil( (j - yLocation + 1) * offset) );
		t2 = static_cast<int>( floor( (j - yLocation + 1) * offset) );
		for (unsigned int i = 0; i < sideLength; i++) {
			if( i < t1 || i > sideLength - t2) continue;
			myImageValue(i + xLocation, j)->Red = triangColour.GetRedNumber();
			myImageValue(i + xLocation, j)->Blue = triangColour.GetBlueNumber();
			myImageValue(i + xLocation, j)->Green = triangColour.GetGreenNumber();
			myImageValue(i + xLocation, j)->Alpha = triangColour.GetAlphaNumber();
		}
	}

	//write generated bitmap image to a file
	myImageValue.WriteToFile(theOutputFile.c_str());
}

Triangle *Triangle::clone() const
{
	return new Triangle(*this);
}

/*
 * if (x, y) is contained
 * Using one vertex as origin point (O)
 * Using two adjacent sides of triangle as two basis (denoted as A and B)
 * Decompose the vertor from O to (x, y) into two basises
 *  {e1 * x1 + e2 * x2 = x
 *  {e1 * y1 + e2 * y2 = y
 *  If contains,
 *  e1>=0 && e2>=0 && e1+e1<=1
 *
 *  det= \x1  x2\
 *       \y1  y2\
 *  det1= \x  x2\
 *        \y  y2\
 *  det2= \x1  x\
 *        \y1  y\
 *  e1= det1/det
 *  e1= det2/det
 */
bool Triangle::contains(unsigned int x, unsigned int y) const
{
	if(sideLength==0){
		return false;
	}

	double det,det1,det2;
	double  x1=sideLength,
	        x2=sideLength/2.0,//y1=0
	        y2=GetHeight(),
	        dx=x-xLocation,
	        dy=y-yLocation;
	det=x1*y2;
	det1=dx*y2-dy*x2;
	det2=x1*dy;

	return det>0 ?(
	                 det1>0&&
	                 det2>0&&
	                 det1+det2<det)
	           :(
	                 det1<0&&
	                 det2<0&&
	                 det1+det2>det)
	             ;
}

/*
 * Check if the Shape extends off the page in Y direction
 * If so, correct it by truncating sideLength
 */
void Triangle::CheckYPartOffPage()
{
	if(yLocation + sideLength*sin60 > pageLength){
		switch (ifDebug) {
			case 2:{
				cerr<<"Thrown in CheckXPartOffPage"<<endl;

				unsigned int h0=GetHeight();
				unsigned int s0=sideLength;
				sideLength=static_cast<unsigned int>((pageLength-yLocation)/sin60);
				throw ShapeYPartOffPageException(xLocation, yLocation, s0, sideLength, h0, GetHeight());
				break;
			}
			case 1:{
				cerr<<"Triangle\n";
				cerr<<ShapeYPartOffPageException::info<<'\n';
				cerr<<"X position was "<<xLocation<<" Y position was "<<yLocation<<'\n';
				cerr<<"X dimension was "<<sideLength<<" Y dimension was "<<GetHeight()<<endl;
				cerr<<"Dimensions reset to include only the part of Triangle on the page"<<'\n';
				sideLength=static_cast<unsigned int>((pageLength-yLocation)/sin60);
				cerr<<"X dimension is "<<sideLength<<" Y dimension is "<<GetHeight()<<endl;
				break;
			}
			default:{
				sideLength=static_cast<unsigned int>((pageLength-yLocation)/sin60);
				break;
			}
		}
	}
}

ostream &operator <<(ostream &os, const Triangle &myTriangle)
{
	cout<<"Printing contents of the Triangle object"<<endl;
	cout<<setw(20)<<"x Location " <<setw(9)<<myTriangle.xLocation<<'\n';
	cout<<setw(20)<<"y Location " <<setw(9)<<myTriangle.yLocation<<'\n';
	cout<<setw(20)<<"side length " <<setw(9)<<myTriangle.sideLength<<'\n';
	cout<<setw(20)<<"Triangle colour " <<setw(9)<<myTriangle.triangColour<<'\n';
	cout<<setw(20)<<"Shapes created " <<setw(9)<<myTriangle.shapesCreated<<'\n';
	cout<<setw(20)<<"Shapes existing " <<setw(9)<<myTriangle.shapesExisting<<'\n';
	cout<<setw(20)<<"Triangles created " <<setw(9)<<myTriangle.trianglesCreated<<'\n';
	cout<<setw(20)<<"Triangles existing " <<setw(9)<<myTriangle.trianglesExisting<<endl;

	return os;
}

#undef sideLength
#undef triangelColour
