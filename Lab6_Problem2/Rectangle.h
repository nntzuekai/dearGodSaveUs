#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include "Gasket.h"

/*
 * Author: Huang Ruikai
 * class Rectangle derived from Shape
 */

class Rectangle:public Shape
{
public:
	Rectangle();
	Rectangle(unsigned int xLocationValue, unsigned int yLocationValue, unsigned int lengthValue, unsigned int HeightValue,Colour blockColourValue);
	Rectangle(unsigned int xLocationValue, unsigned int yLocationValue, Colour blockColourValue);
	Rectangle(const Rectangle& toBeCopied);
	~Rectangle();

	Colour GetBlockColour()const;//same with GetShapeColour
	unsigned int GetWidth()const;//same with GetDimension1

	unsigned int GetHeight() const override;
	static unsigned int GetRectanglesCreated();
	static unsigned int GetRectanglesExisting();

	void SetColour(const Colour blockColourValue);
	void SetXLocation(const unsigned int xLocationValue);
	void SetYLocation(const unsigned int yLocationValue);
	void SetWidth(const unsigned int widthValue);
	void SetDimension1(const unsigned int widthValue);//==SetWidth
	void SetHeight(const unsigned int heightValue);
	static void SetRectanglesCreated(int unsigned numberCreated);
	static void SetRectanglesExisting(int unsigned numberExisting);

	bool DoesIntersect(const Rectangle& rectangle2);//If two rectangles intersect

	const Rectangle &operator = (const Rectangle& Rectangle2);
	bool operator==(const Shape &Shape2) const override;

	friend ostream &operator<< (ostream &os, const Rectangle &myRectangle);

	void Display(BMP& myImageValue, string theOutputFile) const override;

	void Print() const override;

	unsigned int Area() const override;

	bool DoesOverlay(Shape *shape2) const override;

	virtual Rectangle *clone() const override;

	bool operator >(Shape &shape2) const override;
	bool operator <(Shape &shape2) const override;

protected:
	void CheckYPartOffPage() override;

	static unsigned int rectanglesCreated;
	static unsigned int rectanglesExisting;

	unsigned int height=100;

};

#endif // RECTANGLE_H
