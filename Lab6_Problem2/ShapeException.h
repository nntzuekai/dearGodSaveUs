#ifndef SHAPEEXCEPTION_H
#define SHAPEEXCEPTION_H

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class ShapeOffPageException:public out_of_range
{
public:
	ShapeOffPageException(unsigned int x0, unsigned int y0);
	ShapeOffPageException(const ShapeOffPageException&)=default;

	static const string info;
	unsigned int getX0() const;

	unsigned int getY0() const;

private:

	unsigned int x0;
	unsigned int y0;
};


class ShapeXPartOffPageException:public out_of_range
{
public:
	ShapeXPartOffPageException(unsigned int x0, unsigned int y0, unsigned int dimension1_before, unsigned int dimension1_new);
	ShapeXPartOffPageException(const ShapeXPartOffPageException&)=default;

	static const string info;
	unsigned int getX0() const;

	unsigned int getY0() const;

	unsigned int getDimension1_0() const;

	unsigned int getDimension1_1() const;

private:
	unsigned int x0;
	unsigned int y0;
	unsigned int dimension1_0;
	unsigned int dimension1_1;
};

class ShapeYPartOffPageException:public out_of_range
{
public:
	ShapeYPartOffPageException(unsigned int x0, unsigned int y0, unsigned int dimension1_before, unsigned int dimension1_new, unsigned int height0, unsigned int height);
	ShapeYPartOffPageException(const ShapeYPartOffPageException&)=default;

	static const string info;
	unsigned int getX0() const;

	unsigned int getY0() const;

	unsigned int getDimension1_0() const;

	unsigned int getHeight0() const;

	unsigned int getDimension1_1() const;

	unsigned int getHeight() const;

private:

	unsigned int x0;
	unsigned int y0;
	unsigned int dimension1_0;
	unsigned int height0;
	unsigned int dimension1_1;
	unsigned int height;
};


#endif // SHAPEEXCEPTION_H
