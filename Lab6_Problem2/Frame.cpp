#include "Frame.h"

using namespace std;

Frame::Frame(const Frame &frameToCopy)try:
    shapesInPicture(frameToCopy.shapesInPicture.size(),nullptr)
{
	auto p1=shapesInPicture.begin();
	auto p2=frameToCopy.shapesInPicture.begin();

	try{
		for(;
		    p1!=shapesInPicture.end() && p2!=frameToCopy.shapesInPicture.end();
		    p1++,p2++){
			*p1=(*p2)->clone();
		}
	}catch(bad_alloc){
		for(auto p:shapesInPicture){
			delete p;
		}
		throw;
	}

}catch(bad_alloc){
	cerr<<"Unable to create Frame"<<'\n';
	cerr<<"Memory allocation failed"<<endl;
}

Frame::~Frame()
{
	for(auto p:shapesInPicture){
		delete p;
	}
}

void Frame::Print() const
{
	for(const auto p:shapesInPicture){
		p->Print();
	}
}

void Frame::Display(BMP &myImageValue, string theOutputFile) const
{
	for(const auto p:shapesInPicture){
		p->Display(myImageValue,theOutputFile);
	}
}

bool Frame::AppendShape(Shape *newShape)
{
	try{
		shapesInPicture.push_back(newShape);
	}catch(bad_alloc){
		return false;
	}
	return true;
}

unsigned int Frame::FindShape(const Shape &shape) const
{
	auto p=shapesInPicture.begin();
	unsigned int i=0;
	for(;p!=shapesInPicture.end();p++,i++){
		if(shape<**p){
			break;
		}
	}
	return i;
}

bool Frame::InsertShape(unsigned int insertAtIndex, Shape *newShape)
{
	auto p=shapesInPicture.begin();
	try{
		while (insertAtIndex--) {
			++p;
		}
	}catch(...){
		return false;
	}

	if(*p!=newShape){
		return false;
	}

	try{
		shapesInPicture.insert(p,newShape);
	}catch(bad_alloc){
		return false;
	}
	return true;
}

bool Frame::RemoveShape(unsigned int deleteAtIndex, Shape *shapeToRemove)
{
	auto p=shapesInPicture.begin();
	try{
		while (deleteAtIndex--) {
			++p;
		}
	}catch(...){
		return false;
	}

	if(*p!=shapeToRemove){
		return false;
	}

	shapesInPicture.erase(p);
	return true;
}

bool Frame::RemoveLastShape(Shape *shapeToRemove)
{
	(void)shapeToRemove;
	cerr<<"What the hell!"<<endl;///TODO
	return true;
}
