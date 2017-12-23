#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

/*
 * Make aliases for those functions used in Gasket
 */
#define GetSideLength GetDimension1
#define GetTriangColour GetShapeColour
#define SetTriangColour SetShapeColour

/*
 * Author: Huang Ruikai
 * class Triangle derived from Shape
 */

class Triangle:public Shape
{
public:
	Triangle();
	Triangle(unsigned int xLocationValue, unsigned int yLocationValue, unsigned int sideLengthValue, Colour blockColourValue);
	Triangle(unsigned int xLocationValue, unsigned int yLocationValue, Colour blockColourValue);
	Triangle(const Triangle &toBeCopied);
	~Triangle();

	static unsigned int GetTrianglesCreated();
	static unsigned int GetTrianglesExisting();
	unsigned int GetHeight()const override;//Height from bottom vertex to top

	void SetSideLength(const unsigned int setSideLengthValue);
	void SetDimension1(const unsigned int setSideLengthValue);//==SetSideLength
	void SetXLocation(const unsigned int xLocationValue);
	void SetYLocation(const unsigned int yLocationValue);
	static void SetTrianglesCreated(unsigned int numberCreated);
	static void SetTrianglesExisting(unsigned int numberExisting);

	friend ostream &operator << (ostream &os, const Triangle& myTriangle);
	void TriangleDivide(Triangle *subTriangleList ) const;
	const Triangle &operator = (const Triangle& Triangle2);
	bool operator==( const Shape& shape2)const override;
	bool operator > (Shape& shape2)const override;
	bool operator < (Shape& shape2)const override;

	void Print()const override;
	unsigned int Area()const override;
	bool DoesOverlay(Shape* shape2)const override;
	void Display(BMP& myImageValue, string theOutputFile)const override;
	virtual Triangle *clone() const override;
	bool contains(unsigned int x, unsigned int y) const;//If contains (x, y)
protected:
	void CheckYPartOffPage() override;
	static int trianglesCreated;
	static int trianglesExisting;
};


#endif // TRIANGLE_H
