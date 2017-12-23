#ifndef GASKET_H
#define GASKET_H

#include "Triangle.h"

/*
 * Make aliases for those functions used in Gasket
 */
#define GetGasketColour GetShapeColour
#define SetGasketColour SetShapeColour
#define GetSideLength GetDimension1

/*
 * Author: Huang Ruikai
 * class Gasket derived from Shape
 */

class Gasket:public Shape
{
public:
	Gasket();
	Gasket(unsigned int iterations, unsigned int xLocationValue, unsigned int yLocationValue, unsigned int sideLengthValue, Colour gasketColourValue);
	Gasket(const Gasket& toBeCopied);
	~Gasket();

	unsigned int GetIterations() const;
	unsigned int GetHeight() const override;

	void SetIterations(const unsigned int iterationsValue);
	void SetXLocation(const unsigned int xLocationValue);
	void SetYLocation(const unsigned int yLocationValue);
	void SetSideLength(const unsigned int sideLengthValue);
	void SetDimension1(const unsigned int sideLengthValue);//Simply call SetSideLength

	friend ostream &operator << (ostream &os, const Gasket &myGasket);
	const Gasket &operator =(const Gasket &gasket2);
	bool operator ==(const Shape &Shape2)const override;
	bool operator > (Shape &shape2)const override;
	bool operator < (Shape &shape2) const override;

	void Display(BMP& myImageValue, string theOutputFile)const override;
	void Print()const override;
	unsigned int Area()const override;//Area of the smallest triangle containing Gasket
	bool DoesOverlay(Shape* shape2)const override;
	virtual Gasket *clone() const override;

	bool contains(unsigned int x, unsigned int y) const;//Return if the Gasket contains (x, y)

private:
	void GasketDivide(Triangle *listOfSubTriangles, unsigned int numTriangleToDivide);

protected:
	void CheckYPartOffPage() override;

	static unsigned int gasketCreated;
	static unsigned int gasketExisting;

	unsigned int iterations=0;
	Triangle *listOfSubTriangles=nullptr;
	unsigned int lenSubTriList=0;
};


#endif // GASKET_H
