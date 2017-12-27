#include "Shape.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Gasket.h"

int main(){
	Rectangle r1;
	Rectangle r2(r1);
	cout<<(r1==r2)<<endl;
}
