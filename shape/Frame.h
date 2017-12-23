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
	Frame();
	Frame(const Frame & frameToCopy);
	~Frame();

public:
	void Print();
	void Display();
	bool AppendShape( Shape * newShape);
	bool InsertShape( unsigned int insertAtIndex, Shape * newShape);
	bool RemoveShape ( unsigned int deleteAtIndex, Shape * shapeToRemove);
	bool RemoveLastShape (Shape *shapeToRemove);

private:
	list <Shape *> shapesInPicture;

};

#endif
