/*
 * Author: Huang Ruikai
 */

#include "Gasket.h"
#include "Rectangle.h"
#include <typeinfo>
#include <exception>
#include "ShapeException.h"

static const string name="Gasket";
static const string destrct="running Gasket destruct";
static constexpr double sqrt3=sqrt(3.0);
static constexpr double sin60=sqrt3/2;//Height = SideLength * sin(60 deg)

unsigned int Gasket::gasketCreated=0;
unsigned int Gasket::gasketExisting=0;

#define gasketColour shapeColour
#define sideLength dimension1

Gasket::Gasket():
    Shape()
{
	listOfSubTriangles=new Triangle[1]{{xLocation, yLocation, sideLength, gasketColour}};
	lenSubTriList=1;

	++gasketCreated;
	++gasketExisting;
}

Gasket::Gasket(unsigned int iterations, unsigned int xLocationValue, unsigned int yLocationValue, unsigned int sideLengthValue, Colour gasketColourValue):
    Shape(xLocationValue,yLocationValue,sideLengthValue,gasketColourValue),
    iterations(iterations)
{
	try{
		CheckOffPage(name);
		CheckXPartOffPage(name);
		CheckYPartOffPage();
	}catch(...){
		cerr<<"Called from Gasket Constructor 5 arguments"<<endl;
		throw;
	}

	lenSubTriList=static_cast<unsigned int>(pow(3,iterations));//len = 3^ iterations
	listOfSubTriangles=new Triangle[lenSubTriList]{{xLocation, yLocation, sideLength, gasketColour}};

	if(lenSubTriList>1){
		GasketDivide(listOfSubTriangles, lenSubTriList);
	}

	++gasketCreated;
	++gasketExisting;
}

Gasket::Gasket(const Gasket &toBeCopied):
    Shape(toBeCopied),
    iterations(toBeCopied.iterations),
    lenSubTriList(toBeCopied.lenSubTriList)
{
	listOfSubTriangles=new Triangle[lenSubTriList];
	for(unsigned int i=0;i<lenSubTriList;i++){//copy all
		listOfSubTriangles[i]=toBeCopied.listOfSubTriangles[i];
	}

	++gasketCreated;
	++gasketExisting;
}

Gasket::~Gasket()
{
	--gasketExisting;
	delete[] listOfSubTriangles;
	cout<<destrct<<endl;
}

unsigned int Gasket::GetIterations() const
{
	return iterations;
}

/*
 * Height vertically from the bottom vertex to upper side
 * Height = SideLength * sin(60 deg)
 */
unsigned int Gasket::GetHeight() const
{
	return static_cast<unsigned int>(round(sideLength*sin60));
}

void Gasket::SetShapeColour(const Colour colorValue)
{
	shapeColour=colorValue;
	for(decltype (lenSubTriList) i=0;i<lenSubTriList;i++){
		listOfSubTriangles[i].SetShapeColour(colorValue);
	}
}

/*
 * Change value of iterations will cause regeneration of triangles
 */
void Gasket::SetIterations(const unsigned int iterationsValue)
{
	if(iterationsValue==iterations){
		return;
	}

	decltype(listOfSubTriangles) listT=nullptr;
	decltype(lenSubTriList) lenT=0;
	try{
		lenT=static_cast<unsigned int>(pow(3,iterationsValue));
		listT=new Triangle [lenT]{{xLocation, yLocation, sideLength, gasketColour}};
		if(lenT>1){
			GasketDivide(listT, lenT);
		}
	}catch(...){
		delete[] listT;
	}

	delete[] listOfSubTriangles;
	listOfSubTriangles=listT;
	iterations=iterationsValue;
	lenSubTriList=lenT;
}

/*
 * Change value of xLocation may cause regeneration of triangles
 */
void Gasket::SetXLocation(const unsigned int xLocationValue)
{
	if(xLocationValue==xLocation){
		return;
	}

	auto x0=xLocation,y0=yLocation,s0=sideLength;

	xLocation=xLocationValue;

	try{
		CheckOffPage(name);
		CheckXPartOffPage(name);
	}catch(...){
		cerr<<"Called from Gasket SetXLocation"<<endl;
		throw;
	}

	if(s0!=sideLength){//sideLength changed, regeneration is needed
		listOfSubTriangles[0]={xLocation, yLocation, sideLength, gasketColour};
		if(lenSubTriList>1){
			GasketDivide(listOfSubTriangles, lenSubTriList);
		}
		return;
	}

	//sideLength wasn't changed, just need to move the Gasket
	if(xLocation==0&& yLocation==0){//Y alse changed
		for(unsigned int i=0;i<lenSubTriList;i++){
			auto &tri=listOfSubTriangles[i];
			tri.SetXLocation(tri.GetXLocation()-x0);
			tri.SetYLocation(tri.GetYLocation()-y0);
		}
	}
	else if(xLocation!=x0){//only X changed
		auto dx=xLocation-x0;
		for(unsigned int i=0;i<lenSubTriList;i++){
			auto &tri=listOfSubTriangles[i];
			tri.SetXLocation(tri.GetXLocation()+dx);
		}
	}
}

/*
 * Change value of yLocation may cause regeneration of triangles
 *
 * Same logic with SetXLocation
 */
void Gasket::SetYLocation(const unsigned int yLocationValue)
{
	if(yLocationValue==yLocation){
		return;
	}

	auto x0=xLocation,y0=yLocation,s0=sideLength;

	yLocation=yLocationValue;

	try{
		CheckOffPage(name);
		CheckYPartOffPage();
	}catch(...){
		cerr<<"Called from Gasket SetYLocation"<<endl;
		throw;
	}

	if(s0!=sideLength){
		listOfSubTriangles[0]={xLocation, yLocation, sideLength, gasketColour};
		if(lenSubTriList>1){
			GasketDivide(listOfSubTriangles, lenSubTriList);
		}
		return;
	}

	if(xLocation==0&& yLocation==0){
		for(unsigned int i=0;i<lenSubTriList;i++){
			auto &tri=listOfSubTriangles[i];
			tri.SetXLocation(tri.GetXLocation()-x0);
			tri.SetYLocation(tri.GetYLocation()-y0);
		}
	}
	else if(yLocation!=y0){
		auto dy=yLocation-y0;
		for(unsigned int i=0;i<lenSubTriList;i++){
			auto &tri=listOfSubTriangles[i];
			tri.SetYLocation(tri.GetYLocation()+dy);
		}
	}
}

/*
 * Change value of sideLength will cause regeneration of triangles
 */
void Gasket::SetSideLength(const unsigned int sideLengthValue)
{
	if(sideLengthValue==sideLength){
		return;
	}

	sideLength=sideLengthValue;

	try{
		CheckXPartOffPage(name);
		CheckYPartOffPage();
	}catch(...){
		cerr<<"Called from Gasket SetSideLength"<<endl;
		throw;
	}

	listOfSubTriangles[0]={xLocation, yLocation, sideLength, gasketColour};
	if(lenSubTriList > 1) {
		GasketDivide(listOfSubTriangles, lenSubTriList);
	}
}

void Gasket::SetDimension1(const unsigned int sideLengthValue)
{
	SetSideLength(sideLengthValue);
}

const Gasket &Gasket::operator =(const Gasket &gasket2)
{
	decltype(listOfSubTriangles) listT=nullptr;

	this->Shape::operator =(gasket2);//base part

	try{
		listT=new Triangle[gasket2.lenSubTriList];
		for(unsigned int i=0;i<gasket2.lenSubTriList;i++){
			listT[i]=gasket2.listOfSubTriangles[i];
		}
	}catch(...){
		delete[] listT;
	}


	delete[] listOfSubTriangles;
	listOfSubTriangles=listT;

	lenSubTriList=gasket2.lenSubTriList;
	iterations=gasket2.iterations;

	return *this;
}

bool Gasket::operator ==(const Shape &Shape2) const
{
	if(auto gas=dynamic_cast<const Gasket*> (&Shape2)){
		return this->Shape::operator ==(Shape2)&&//Base part
		        iterations==gas->iterations;
	}
	else{
		return false;
	}
}

bool Gasket::operator >(Shape &shape2) const
{
	return Area()>shape2.Area();
}

bool Gasket::operator <(Shape &shape2) const
{
	return Area()<shape2.Area();
}

void Gasket::Display(BMP &myImageValue, string theOutputFile) const
{
	for(unsigned int i=0;i<lenSubTriList;i++){
		listOfSubTriangles[i].Display(myImageValue, theOutputFile);
	}
}

void Gasket::Print() const
{
	cout<<*this;
}

/*
 * Area = sqrt(3) * SideLength^2 / 4
 */
unsigned int Gasket::Area() const
{
	return static_cast<unsigned int>(round(sqrt3*sideLength*sideLength/4));
}

bool Gasket::DoesOverlay(Shape *shape2) const
{
	if(auto rec=dynamic_cast<Rectangle*>(shape2)){//Is a rectangle
		return (xLocation>=rec->GetXLocation())&&(xLocation<=rec->GetXLocation()+rec->GetWidth())&&
		        (yLocation>=rec->GetXLocation())&&(yLocation<=rec->GetYLocation()+rec->GetHeight())&& //(x, y) shouble be in rectangle
		        (xLocation+sideLength<=rec->GetXLocation()+rec->GetWidth())&& //inside in X dimension
		        (yLocation+GetHeight()<=rec->GetYLocation()+rec->GetHeight()); //inside in Y dimension
	}
	if(auto tri=dynamic_cast<Triangle*>(shape2)){//is a triangle
		return tri->contains(xLocation,yLocation)&& //All three vertices should be in shape2
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

Gasket *Gasket::clone() const
{
	return new Gasket(*this);
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
bool Gasket::contains(unsigned int x, unsigned int y) const
{
	if(sideLength==0){
		return false;
	}

	double det,det1,det2;
	double  x1=sideLength,
	        x2=sideLength/2.0,
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
 * Divide the Triange in listOfSubTriangle[0] into three.
 * Put them into trisection positions from [0] to [numTriangleToDivide]
 */
void Gasket::GasketDivide(Triangle* listOfSubTriangles, unsigned int numTriangleToDivide)
{
	Triangle &tri = listOfSubTriangles[0];
	Colour color = tri.GetTriangColour();
	auto x = tri.GetXLocation();
	auto y = tri.GetYLocation();
	auto l = tri.GetSideLength();
	auto num = numTriangleToDivide / 3;

	listOfSubTriangles[2 * num] = {x + l / 4, static_cast<unsigned int>(y + l*sin60 / 2), l / 2, color};
	listOfSubTriangles[num] = {x + l / 2, y, l / 2, color};
	listOfSubTriangles[0] = {x, y, l / 2, color};

	if(l / 2 <= 1) {
		return;
	}

	if(num <= 1) {
		return;
	}

	GasketDivide(listOfSubTriangles, num);
	GasketDivide(&listOfSubTriangles[num], num);
	GasketDivide(&listOfSubTriangles[2 * num], num);
}

/*
 * Check if the Shape extends off the page in Y direction
 * If so, correct it by truncating sideLength
 */
void Gasket::CheckYPartOffPage()
{
	if(yLocation+sideLength*sin60>pageLength){
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
				cerr<<"Gasket\n";
				cerr<< ShapeYPartOffPageException::info<<'\n';
				cerr<<"X position was "<<xLocation<<" Y position was "<<yLocation<<'\n';
				cerr<<"X dimension was "<<sideLength<<" Y dimension was "<<GetHeight()<<endl;
				cerr<<"Dimensions reset to include only the part of Gasket on the page"<<'\n';
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

ostream &operator <<(ostream &os, const Gasket &myGasket)
{
	cout<<"Printing contents of the Gasket object\n";
	cout<<setw(20)<<"iterations " <<setw(9) <<myGasket.iterations<<'\n';
	cout<<setw(20)<<"x location "<<setw(9) <<myGasket.xLocation<<'\n';
	cout<<setw(20)<<"y location " <<setw(9) <<myGasket.yLocation<<'\n';
	cout<<setw(20)<<"side length "<<setw(9) <<myGasket.sideLength<<'\n';
	cout<<setw(20)<<"Gasket Colour "<<setw(9) <<myGasket.gasketColour<<'\n';
	cout<<setw(20)<<"lenSubTriList "<<setw(9) <<myGasket.lenSubTriList<<'\n';
	cout<<setw(20)<<"Shapes created "<<setw(9) <<myGasket.shapesCreated<<'\n';
	cout<<setw(20)<<"Shapes existing "<<setw(9) <<myGasket.shapesExisting<<'\n';
	cout<<setw(20)<<"Gaskets created "<<setw(9) <<myGasket.gasketCreated<<'\n';
	cout<<setw(20)<<"Gaskets existing "<<setw(9) <<myGasket.gasketExisting<<'\n'
	   <<endl;


	for(unsigned int i=0;i<myGasket.lenSubTriList;i++){
		cout<<myGasket.listOfSubTriangles[i];
		cout<<endl;
	}

	return os;
}

#undef gasketColour
#undef sideLength
