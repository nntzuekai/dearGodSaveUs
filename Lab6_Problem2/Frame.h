#ifndef FrameFlag
#define FrameFlag

#include <iostream>
#include "Shape.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Gasket.h"
#include <list>

using namespace std;

class Frame
{
	Frame()=default;
	Frame(const Frame & frameToCopy);
	~Frame();

public:
	void Print()const;
	void Display(BMP& myImageValue, string theOutputFile)const;
	bool AppendShape(Shape *newShape);
	unsigned int FindShape(const Shape &shape) const;
	bool InsertShape( unsigned int insertAtIndex, Shape *newShape);
	bool RemoveShape ( unsigned int deleteAtIndex, Shape *shapeToRemove);
	bool RemoveLastShape (Shape *shapeToRemove);

private:
	list <Shape *> shapesInPicture;

};

#endif
