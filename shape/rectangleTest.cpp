#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <string>
#include "EasyBMP.h"
#include "Colour.h"
#include "Shape.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Gasket.h"
#include "DisplayBackground.h"
using namespace std;


// main program to test class Rectangle
// Creates and prints a rectangle
int main()
{
	//Please note that this is the correct location for BMP myImage
	//The program will work if you make this declaration global (as indicated in lab writeup)
	//However global variables should not be used as arguments of functions
	BMP myImage;
	Colour C1(0, 0, 255, 255);     //dark blue
	Colour C2(0, 0, 0, 255);	   //black
	Colour CB(0, 255, 0, 255);     //green
	Colour C3(255,0,0,255);		   //red
	Colour C4(128,128,128,128);	   //grey 
	Colour C5( 100, 200, 255, 170);//light blue 
	Colour C6( 255, 0, 255, 255);  //Pink  
	Colour C7( 255, 255, 0, 255 ); //Yellow
	Colour C8( 155, 155,255,255);  //Purple
	string numbers; 
	string myFileName;
	Shape* shapeArray[45];

	Rectangle R1; 
	Rectangle R2( 220, 440, C2);
	Rectangle R3( 350, 355, 225, 250, C3 );
	Rectangle R4( 40, 300, 410, 450, C4);
	Rectangle R5( 100, 410, 330, 290, C5);
	Rectangle R6(R4);
	Rectangle R7( 200, 190, 200, 150, C7 );
	Rectangle R8( 50, 100, 280, 160, C8);
	Triangle TC1(100, 100, 400, C4);
	Triangle TC2(300, 300, 50,  C5);
	Gasket   GC1(4, 50, 150, 500, C6);
	Gasket   GC2(2, 340, 450, 90, C7);

	cout << "TESTING THREE CONSTRUCTORS: Printing R1 (default), R2(3 arg) and R3( 4 arg)" << endl;
	R1.Print();
	cout << endl;
	R2.Print();
	cout << endl;
	R3.Print();
	cout << endl << endl << endl;


	cout << "TESTING COPY CONSTRUCTOR" << endl;
	cout << "R4, rectangle to copy" << endl;
	R4.Print();
	cout << endl << "R6, created with copy constructor " << endl;
	R6.Print();
	cout << endl << "testing self copy" << endl;
	R6 = Rectangle(R6);

	cout << endl << endl << endl;


	cout << "TESTING GETTERS" << endl;
	cout << "getting values from R6" << endl;
	R6.Print();
	cout << endl;
	cout << "Getting Width " << R6.GetDimension1() << endl;
	cout << "Getting Height " << R6.GetHeight() << endl;
	cout << "Getting xLocation " << R6.GetXLocation() << endl; 
	cout << "Getting yLocation " << R6.GetYLocation() << endl;
	cout << "Getting rectanglesCreated " << R6.GetRectanglesCreated()<< endl;
	cout << "Getting rectanglesExisting " << R6.GetRectanglesExisting() << endl;
	cout << "Getting blockColour " << R6.GetShapeColour() << endl;
	cout << endl << endl << endl;


	cout << "TESTING SETTERS: changing default values in R1 and R2" << endl;
	cout << "None of the following 7 changes result in a Rectangle that"  
		<< endl << " is partially or completely off the page" << endl;
	cout << endl << "R1 before changes" << endl;     
	R1.Print();
	cout << endl;
	R1.SetDimension1(220);
	cout << "set R1.width set to 220" << endl;
	R1.SetHeight(100);
	cout << "set R1.height set to 100" << endl;
	R1.SetXLocation(100);
	cout << "set R1.xLocation set to 100" << endl;
	R1.SetYLocation(225);
	cout << "set R1.yLocation set to 225" << endl;
	R1.SetShapeColour(C6);
	cout << "set R1.Colour set to " << C6 << endl << endl;
	cout << "modified R1" << endl;
	R1.Print();
	cout << endl << endl;

	cout << "R2 before changes" << endl;
	R2.Print();
	cout << endl;
	cout << "set R2.height to 280" << endl;
	cout << "set R2.width to 100" << endl;
	R2.SetHeight(225);
	R2.SetDimension1(100);
	cout << "modified R2" << endl;
	R2.Print();
	cout << endl << endl << endl;


	cout << "TESTING OVERLAY" << endl;
	if(R1.DoesOverlay(&R2))
	{
		cout << "R1 overlays R2" << endl;
	}
	if(R1.DoesOverlay(&R3))
	{
		cout << "R1 overlays R3" << endl;
	}
	if(R1.DoesOverlay(&R4))
	{
		cout << "R1 overlays R4" << endl;
	}
	if(R1.DoesOverlay(&R5))
	{
		cout << "R1 overlays R5" << endl;
	}
	if(R1.DoesOverlay(&R7))
	{
		cout << "R1 overlays R7" << endl;
	}
	if(R1.DoesOverlay(&R8))
	{
		cout << "R1 overlays R8" << endl;
	}
	if(R2.DoesOverlay(&R1))
	{
		cout << "R2 overlays R1" << endl;
	}
	if(R2.DoesOverlay(&R3))
	{
		cout << "R2 overlays R3" << endl;
	}
	if(R2.DoesOverlay(&R4))
	{
		cout << "R2 overlays R4" << endl;
	}
	if(R2.DoesOverlay(&R5))
	{
		cout << "R2 overlays R5" << endl;
	}
	if(R2.DoesOverlay(&R7))
	{
		cout << "R2 overlays R7" << endl;
	}
	if(R2.DoesOverlay(&R8))
	{
		cout << "R2 overlays R8" << endl;
	}
	if(R3.DoesOverlay(&R1))
	{
		cout << "R3 overlays R1" << endl;
	}
	if(R3.DoesOverlay(&R2))
	{
		cout << "R3 overlays R2" << endl;
	}
	if(R3.DoesOverlay(&R4))
	{
		cout << "R3 overlays R4" << endl;
	}
	if(R3.DoesOverlay(&R5))
	{
		cout << "R3 overlays R5" << endl;
	}
	if(R3.DoesOverlay(&R7))
	{
		cout << "R3 overlays R7" << endl;
	}
	if(R3.DoesOverlay(&R8))
	{
		cout << "R3 overlays R8" << endl;
	}
	if(R4.DoesOverlay(&R1))
	{
		cout << "R4 overlays R1" << endl;
	}
	if(R4.DoesOverlay(&R2))
	{
		cout << "R4 overlays R2" << endl;
	}
	if(R4.DoesOverlay(&R3))
	{
		cout << "R4 overlays R3" << endl;
	}	
	if(R4.DoesOverlay(&R5))
	{
		cout << "R4 overlays R5" << endl;
	}
	if(R4.DoesOverlay(&R7))
	{
		cout << "R4 overlays R7" << endl;
	}
	if(R4.DoesOverlay(&R8))
	{
		cout << "R4 overlays R8" << endl;
	}
	if(R5.DoesOverlay(&R1))
	{
		cout << "R5 overlays R1" << endl;
	}
	if(R5.DoesOverlay(&R2))
	{
		cout << "R5 overlays R2" << endl;
	}
	if(R5.DoesOverlay(&R3))
	{
		cout << "R5 overlays R3" << endl;
	}	
	if(R5.DoesOverlay(&R4))
	{
		cout << "R5 overlays R4" << endl;
	}	
	if(R5.DoesOverlay(&R7))
	{
		cout << "R5 overlays R7" << endl;
	}	
	if(R5.DoesOverlay(&R8))
	{
		cout << "R5 overlays R8" << endl;
	}
	if(R7.DoesOverlay(&R1))
	{
		cout << "R7 overlays R1" << endl;
	}
	if(R7.DoesOverlay(&R2))
	{
		cout << "R7 overlays R2" << endl;
	}
	if(R7.DoesOverlay(&R3))
	{
		cout << "R7 overlays R3" << endl;
	}	
	if(R7.DoesOverlay(&R4))
	{
		cout << "R7 overlays R4" << endl;
	}	
	if(R7.DoesOverlay(&R5))
	{
		cout << "R7 overlays R5" << endl;
	}	
	if(R7.DoesOverlay(&R8))
	{
		cout << "R7 overlays R8" << endl;
	}	
	if(R8.DoesOverlay(&R1))
	{
		cout << "R8 overlays R1" << endl;
	}
	if(R8.DoesOverlay(&R2))
	{
		cout << "R8 overlays R2" << endl;
	}
	if(R8.DoesOverlay(&R3))
	{
		cout << "R8 overlays R3" << endl;
	}	
	if(R8.DoesOverlay(&R4))
	{
		cout << "R8 overlays R4" << endl;
	}	
	if(R8.DoesOverlay(&R5))
	{
		cout << "R8 overlays R5" << endl;
	}	
	if(R8.DoesOverlay(&R7))
	{
		cout << "R8 overlays R7" << endl;
	}	
	cout << endl << endl << endl;


	cout << "TESTING DISPLAY OF RECTANGLES" << endl;
	//Create the bitmap
	//Load the background bitmap
	//Plot each rectangle to the bitmap
	//Note the last rectangle plotted will appear on
	//to of previous rectangles
	InitBackground(myImage, CB, 600, 800);
	R4.Display(myImage, "rectangleTest.bmp");
	R3.Display(myImage, "rectangleTest.bmp");
	R8.Display(myImage, "rectangleTest.bmp");
	R5.Display(myImage, "rectangleTest.bmp");
	R2.Display(myImage, "rectangleTest.bmp");
	R7.Display(myImage, "rectangleTest.bmp");
	R1.Display(myImage, "rectangleTest.bmp");

	cout << endl << endl << endl;

	cout << "TESTING = OPERATOR"<< endl;
	cout << "printing R5"<< endl;
	R5.Print();
	cout << "printing R1" << endl;
	R1.Print();
	R1 = R1;
	cout << endl;
	cout << "printing R1 after R1=R1"<< endl;
	R1.Print();
	cout << endl;
	R1 = R5;
	cout << endl;
	cout << "printing R1 after R1=R5"<< endl;
	R1.Print();
	cout << endl << endl << endl;

	cout << "TESTING THE << OPERATOR" << endl;
	cout << "R5" << endl << R5;
	cout << endl << endl << endl;

	//Test the == operator
	cout << "Testing == answer should be true (1) " << (R3==R4);
	cout << endl;
	cout << "Testing == answer should be false (0) " << (R3==R1);
	cout << endl << endl << endl;

	//Test the < operator
	cout << "testing Rectangle < Triangle, answer should be true (1) " <<  (R7 < TC1);
	cout << endl;	
	cout << "testing Rectangle < Gasket, answer should be true (1) " <<  (R5 < GC1);
	cout << endl;
	cout << "testing Rectangle < Rectangle, answer should be true (1) " <<  (R3 < R4);
	cout << endl;
	cout << "testing Rectangle < Triangle, answer should be false (0) " << (R3 < TC2);
	cout << endl;	
	cout << "testing Rectangle < Gasket, answer should be false (0) " << (R4 < GC2);
	cout << endl;
	cout << "testing Rectangle < Rectangle, answer should be false (0) " << (R4 < R2);
	cout << endl << endl << endl;

	//Test the > operator
	cout << "testing Rectangle > Triangle, answer should be true (1) " <<  (R4 > TC1);
	cout << endl;	
	cout << "testing Rectangle > Gasket, answer should be true (1) " <<  (R4 > GC2);
	cout << endl;
	cout << "testing Rectange > Rectangle, answer should be true (1) " <<  (R4 > R5);
	cout << endl;
	cout << "testing Rectangle > Triangle, answer should be false (0) " << (R3 > TC1);
	cout << endl;	
	cout << "testing Rectangle > Gasket, answer should be false (0) " << (R1 > GC1);
	cout << endl;
	cout << "testing Rectangle > Rectangle, answer should be false (0) " << (R7 > R8);
	cout << endl << endl << endl;

	cout << "TESTING RECTANGLES OVERLAPPING EDGES OF PAGE" << endl;
	ResetBackground(myImage, CB, 600, 800);

	cout << "RECTANGLE BOTH xLocation AND yLocation OFF THE PAGE";
	cout << ": plotted Red" << endl;
	Rectangle R10( -5, 990, 300, 250, C3 );
	cout << endl;
	R10.Display(myImage, "rectangleTestOut.bmp");
	R10.Print();	

	cout << endl << "RECTANGLE, yLocation OFF THE PAGE";
	cout << ": plotted Black" << endl;	
	Rectangle R11( 100, 977, 200, 200, C2);
	cout << endl;
	R11.Display(myImage, "rectangleTestOut.bmp");
	R11.Print();

	cout << endl << "RECTANGLE, xLocation OFF THE PAGE";
	cout << ": plotted dark Blue" << endl;	
	Rectangle R12( 800, 100, 140, 150, C1); 
	cout << endl;
	R12.Display(myImage, "rectangleTestOut.bmp");
	R12.Print();

	cout << endl << "RECTANGLE, xLocation ON PAGE, xLocation+width OFF THE PAGE";
	cout << ": plotted Pink" << endl;
	Rectangle R13( 450, 150, 300,200, C6);
	cout << endl;
	R13.Display(myImage, "rectangleTestOut.bmp");
	R13.Print();
	cout << endl << "move x off page, change colour" << endl;
	R13.SetXLocation(500);


	cout << endl << "RECTANGLE, yLocation ON PAGE, yLocation+height OFF THE PAGE";
	cout << ": plotted Light Blue" << endl;
	Rectangle R14( 277, 688, 175, 220, C8);
	cout << endl;
	R14.Display(myImage, "rectangleTestOut.bmp");
	R14.Print();

	cout << endl << "RECTANGLE, xLocation ON PAGE, xLocation+width OFF THE PAGE";
	cout << endl << "RECTANGLE, yLocation ON PAGE, yLocation+height OFF THE PAGE";
	cout << ": plotted Grey" << endl;
	Rectangle R15( 522, 553, 128, 300, C4);
	cout << endl;
	R15.Display(myImage, "rectangleTestOut.bmp");
	R15.Print();

	cout << endl << "mutator for x value moves partially off page";
	cout << endl << "mutator for y value moves partially off page";
	cout  << endl << "x moved to 580,  y moved to 700";
	cout << ": plotted Yellow" << endl;
	Rectangle R19( 500, 450, 80, 340, C4);
	R19.SetShapeColour(C7);
	R19.SetXLocation(580);
	R19.SetYLocation(700);
	R19.Display(myImage, "rectangleTestOut.bmp");
	R19.Print();
	cout << endl;
	R19.Display(myImage, "rectangleTestOut.bmp");
	R19.Print();

	cout << endl << "mutator for x value moves partially off page";
	cout  << endl << "x moved to 480";
	cout << ": plotted Dark Blue" << endl;
	Rectangle R16( 50, 0, 140, 150, C1);
	R16.SetXLocation(580);
	R16.Display(myImage, "rectangleTestOut.bmp");
	R16.Print();

	cout << endl << "mutator for y value moves partially off page";
	cout  << endl << "y moved to 670";
	cout << ": plotted Black" << endl;
	Rectangle R17( 0, 0, 100, 200, C2);
	R17.SetYLocation(670);
	R17.Display(myImage, "rectangleTestOut.bmp");
	R17.Print();

	cout << endl << "mutator for width value moves partially off page";
	cout  << endl << "width moved to 370";
	cout << ": plotted Purple" << endl;
	Rectangle R18( 440, 400, 100, 120, C8);
	R18.SetDimension1(370);
	R18.Display(myImage, "rectangleTestOut.bmp");
	R18.Print();

	cout << endl << "mutator for height value moves partially off page";
	cout  << endl << "height moved to 370";
	cout << ": plotted Red" << endl;
	Rectangle R20( 110, 600, 100, 120, C7);
	R20.SetHeight(250);
	R20.Display(myImage, "rectangleTestOut.bmp");
	R20.Print();

	cout << endl << endl << endl;
	cout << "????????????????????????????????????????????????????";


	cout << "BEGIN TRIANGLE TEST" << endl << endl;
	Triangle T1;
	Triangle T2( 280, 524, 200, C2);
	Triangle T3( 250, 300, 325,  C3 );
	Triangle T4( 44, 70, 450,  C4);
	Triangle T5( 400, 590, 180,  C5);
	Triangle T6(T2);
	shapeArray[8] = &T1;
	shapeArray[9] = &T2;
	shapeArray[10] = &T3;
	shapeArray[11] = &T4;
	shapeArray[12] = &T5;
	shapeArray[13] = &T6;


	cout << "TESTING THREE CONSTRUCTORS: Printing T1(default), T2(3arg) and T3(4arg)" << endl;
	cout << "ALSO TESTING PRINT FUNCTION" << endl;
	ResetBackground(myImage, CB, 600, 800);
	T1.Print();
	cout << endl;
	T2.Print();
	cout << endl;
	T3.Print();
	cout << endl << endl << endl;


	cout << "TESTING COPY CONSTRUCTOR" << endl;	
	cout << "Triangle to copy" << endl;
	T2.Print();
	cout << "Triangle created with copy constructor" << endl;
	T6.Print();
	cout << endl << endl << endl;


	cout << "TESTING GETTERS" << endl;    
	cout << "getting values from T6" << endl;
	T6.Print();
	cout << endl;
	cout << "Getting Width " << T6.GetDimension1() << endl;
	cout << "Getting xLocation " << T6.GetXLocation() << endl; 
	cout << "Getting yLocation " << T6.GetYLocation() << endl;
	cout << "Getting trianglesCreated " << T6.GetTrianglesCreated()<< endl;
	cout << "Getting trianglesExisting " << T6.GetTrianglesExisting() << endl;
	cout << "Getting blockColour " << T6.GetShapeColour() << endl;
	cout << endl << endl << endl;


	cout << "TESTING SETTERS: changing default values in T1 and T2" << endl;
	cout << "None of the following 6 changes result in a Triangle that"  
		<< endl << " is partially or completely off the page" << endl;
	cout << endl << "T1 before changes" << endl; 
	T1.Print();
	cout << endl;
	cout << "setting R1.sideLength to 330" << endl;
	T1.SetDimension1(330);
	cout << "setting R1.xLocation to 25"  << endl;
	T1.SetXLocation(25);
	cout << "setting R1.yLocation to 480"  << endl;
	T1.SetYLocation(480);
	cout << "setting R1.TriangleColour to C7" << endl;
	T1.SetShapeColour(C7);
	cout << "modified R1" << endl;
	T1.Print();
	cout << endl;
	cout << "T2 before changes" << endl;
	T2.Print();
	cout << endl << "setting sideLength to 50" << endl;
	T2.SetDimension1(210);
	T6.SetDimension1(210);
	cout << "modified R2" << endl;
	T2.Print();
	cout << endl << endl << endl;


	cout << "TESTING DISPLAY OF TRIANGLES" << endl;
	T4.Display(myImage, "triangleTest.bmp");
	T3.Display(myImage, "triangleTest.bmp");
	T5.Display(myImage, "triangleTest.bmp");
	T1.Display(myImage, "triangleTest.bmp");
	T2.Display(myImage, "triangleTest.bmp");
	T6.Display(myImage, "triangleTest.bmp");
	cout << endl << endl << endl;

	cout << "TESTING OVERLAY" << endl;
	if(T1.DoesOverlay(&T2))
	{
		cout << "T1 overlays T2" << endl;
	}
	if(T1.DoesOverlay(&T3))
	{
		cout << "T1 overlays T3" << endl;
	}
	if(T1.DoesOverlay(&T4))
	{
		cout << "T1 overlays T4" << endl;
	}
	if(T1.DoesOverlay(&T5))
	{
		cout << "T1 overlays T5" << endl;
	}
	if(T1.DoesOverlay(&T6))
	{
		cout << "T1 overlays T6" << endl;
	}
	if(T2.DoesOverlay(&T1))
	{
		cout << "T2 overlays T1" << endl;
	}
	if(T2.DoesOverlay(&T3))
	{
		cout << "T2 overlays T3" << endl;
	}
	if(T2.DoesOverlay(&T4))
	{
		cout << "T2 overlays T4" << endl;
	}
	if(T2.DoesOverlay(&T5))
	{
		cout << "T2 overlays T5" << endl;
	}
	if(T2.DoesOverlay(&T6))
	{
		cout << "T2 overlays T6" << endl;
	}
	if(T3.DoesOverlay(&T1))
	{
		cout << "T3 overlays T1" << endl;
	}
	if(T3.DoesOverlay(&T2))
	{
		cout << "T3 overlays T2" << endl;
	}
	if(T3.DoesOverlay(&T4))
	{
		cout << "T3 overlays T4" << endl;
	}
	if(T3.DoesOverlay(&T5))
	{
		cout << "T3 overlays T5" << endl;
	}
	if(T3.DoesOverlay(&T6))
	{
		cout << "T3 overlays T6" << endl;
	}
	if(T4.DoesOverlay(&T1))
	{
		cout << "T4 overlays T1" << endl;
	}
	if(T4.DoesOverlay(&T2))
	{
		cout << "T4 overlays T2" << endl;
	}
	if(T4.DoesOverlay(&T3))
	{
		cout << "T4 overlays T3" << endl;
	}	
	if(T4.DoesOverlay(&T5))
	{
		cout << "T4 overlays T5" << endl;
	}
	if(T4.DoesOverlay(&T6))
	{
		cout << "T4 overlays T5" << endl;
	}
	if(T5.DoesOverlay(&T1))
	{
		cout << "T5 overlays T1" << endl;
	}
	if(T5.DoesOverlay(&T2))
	{
		cout << "T5 overlays T2" << endl;
	}
	if(T5.DoesOverlay(&T3))
	{
		cout << "T5 overlays T3" << endl;
	}	
	if(T5.DoesOverlay(&T4))
	{
		cout << "T5 overlays T4" << endl;
	}	
	if(T5.DoesOverlay(&T6))
	{
		cout << "T5 overlays T6" << endl;
	}	    
	if(T6.DoesOverlay(&T1))
	{
		cout << "T6 overlays T1" << endl;
	}
	if(T6.DoesOverlay(&T2))
	{
		cout << "T6 overlays T2" << endl;
	}
	if(T6.DoesOverlay(&T3))
	{
		cout << "T6 overlays T3" << endl;
	}	
	if(T6.DoesOverlay(&T4))
	{
		cout << "T6 overlays T4" << endl;
	}	
	if(T6.DoesOverlay(&T5))
	{
		cout << "T6 overlays T5" << endl;
	}	
	cout << endl << endl << endl;

	cout << "TESTING = OPERATOR"<< endl;
	cout << "printing T3"<< endl;
	T3.Print();
	cout << "printing T4" << endl;
	T4.Print();
	cout << endl;
	cout << "printing T4 after T4=T3"<< endl;
	T4 = T3;
	T4.Print();
	cout << endl << endl << endl;

	cout << "TESTING THE << OPERATOR" << endl;
	cout << "T5" << endl << T5;
	cout << endl << endl << endl;

	//Test the == operator
	cout << "Testing == answer should be true (1) " << (T3==T4);
	cout << endl;
	cout << "Testing == answer should be false (0) " << (T3==T1);
	cout << endl << endl << endl;

	//Test the < operator
	cout << "testing Triangle < Triangle, answer should be true (1) " <<  (T6 < T3);
	cout << endl;	
	cout << "testing Triangle < Gasket, answer should be true (1) " <<  (T5 < GC1);
	cout << endl;
	cout << "testing Triangle < Rectangle, answer should be true (1) " <<  (T3 < R6);
	cout << endl;
	cout << "testing Triangle < Triangle, answer should be false (0) " << (T1 < T3);
	cout << endl;	
	cout << "testing Triangle < Gasket, answer should be false (0) " << (T4 < GC2);
	cout << endl;
	cout << "testing Triangle < Rectangle, answer should be false (0) " << (T1 < R7);
	cout << endl << endl << endl;

	//Test the > operator
	cout << "testing Triangle > Triangle, answer should be true (1) " <<  (T4 > T2);
	cout << endl;	
	cout << "testing Triangle > Gasket, answer should be true (1) " <<  (T6 > GC2);
	cout << endl;
	cout << "testing Triangle > Rectangle, answer should be true (1) " <<  (T4 > R2);
	cout << endl;
	cout << "testing Triangle > Triangle, answer should be false (0) " << (T5 > T6);
	cout << endl;	
	cout << "testing Triangle > Gasket, answer should be false (0) " << (T1 > GC1);
	cout << endl;
	cout << "testing Triangle > Rectangle, answer should be false (0) " << (T2 > R7);
	cout << endl << endl << endl;


	cout << endl << "TESTING TRIANGLES OVERLAPPING EDGES OF PAGE" << endl << endl;
	cout << "AND TESTING TRIANGLES OUTSIDE THE PAGE" << endl;
	ResetBackground(myImage, CB, 600, 800);
	cout << "TRIANGLE BOTH xLocation AND yLocation OFF THE PAGE";
	cout << ": plotted Red" << endl << endl;
	Triangle T10( -20, -100, 400, C3 );
	cout << endl << endl;
	T10.Display(myImage, "triangleTestOut.bmp");
	T10.Print();
	cout << endl << "TRIANGLE, yLocation OFF THE PAGE";
	cout << ": plotted Black" << endl << endl;;
	Triangle T11( 140, 900, 300, C2);
	cout << endl << endl;
	T11.Display(myImage, "triangleTestOut.bmp");
	T11.Print();
	cout << endl << "TRIANGLE, xLocation OFF THE PAGE";
	cout << ": plotted Grey" << endl << endl;
	Triangle T12( 700, 400, 200, C4); 
	cout << endl;
	T12.Display(myImage, "triangleTestOut.bmp");	
	T12.Print();
	cout << endl << "TRIANGLE, xLocation ON PAGE, xLocation+width OFF THE PAGE";
	cout << ": plotted Dark Blue" << endl << endl;
	Triangle T13( 400, 50, 250, C1);
	cout << endl << endl;
	T13.Display(myImage, "triangleTestOut.bmp");
	T13.Print();
	cout << endl << "TRIANGLE, yLocation ON PAGE, yLocation+height OFF THE PAGE";
	cout << ": plotted Grey" << endl << endl;
	Triangle T14( 180, 550, 410, C4);
	cout << endl << endl;
	T14.Display(myImage, "triangleTestOut.bmp");
	T14.Print();
	cout << endl << "TRIANGLE, xLocation ON PAGE, xLocation+sideLength OFF THE PAGE";
	cout << endl << "TRIANGLE, yLocation ON PAGE, yLocation+height OFF THE PAGE";
	cout << endl << "TRIANGLE, yLocation+height off page after scaling for x";
	cout << ": plotted Pink" << endl;
	Triangle T15( 350, 600, 330, C6);
	cout << endl;
	T15.Print();
	T15.Display(myImage, "triangleTestOut.bmp");
	cout << endl << "TRIANGLE, xLocation ON PAGE, xLocation+sideLength OFF THE PAGE";
	cout << endl << "TRIANGLE, yLocation ON PAGE, yLocation+height OFF THE PAGE";
	cout << endl << "TRIANGLE, yLocation+height on page after scaling for x";
	cout << ": plotted Light Blue" << endl << endl;
	Triangle T16( 300,300,400, C5);
	cout << endl << endl;
	T16.Display(myImage, "triangleTestOut.bmp");
	T16.Print();

	// TEST MUTATORS Moving off the page
	cout << "Mutators moving the shape completely or partially off the page" << endl
		<< endl;
	cout << "TRIANGLE: move triangle so xLocation=650, off page";
	cout << ": plotted yellow at 0,0" << endl << endl;
	Triangle T17( 420, 400, 120, C7);
	T17.SetXLocation(650); 
	T17.Display(myImage, "triangleTestOut.bmp");
	T17.Print();
	cout << endl << endl;

	cout << endl << "move triangle so triangle in y so it is partially off the page"
		<< endl << " change ylocation to 530 ";
	cout << ": plotted Purple" << endl << endl;
	Triangle T18( 50, 350, 330, C8);
	T18.SetYLocation(530);
	T18.Print();
	T18.Display(myImage, "triangleTestOut.bmp");
	cout << endl << endl << endl;

	cout << endl << "change sidelength so triangle is off the page in y"
		<< endl << " change sideLength to 165" << endl << "TRIANGLE: move T15, change sideLength so off page in y";
	cout << endl << ": plotted Black" << endl;
	Triangle T20( 50, 675, 100, C2);
	T20.SetDimension1(165);	cout << endl;
	T20.Print();
	T20.Display(myImage, "triangleTestOut.bmp");
	cout << endl << endl << endl;

	cout << endl << "move triangle so triangle in x so it is partially off the page"
		<< endl << " change xlocation to 510 " ;
	cout <<  ": plotted Red" << endl;
	Triangle T21( 450, 230, 130, C3);
	T21.SetXLocation(510);	
	T21.Print();
	T21.Display(myImage, "triangleTestOut.bmp");
	cout << endl << endl << endl;

	cout << endl << "change sidelength so triangle is off the page in x"
		<< endl << " change sideLength to 165";
	cout << ": plotted Purple" << endl;
	Triangle T22( 470, 475, 100, C8);
	T22.SetDimension1(165);	
	T22.Print();
	T22.Display(myImage, "triangleTestOut.bmp");

	cout << endl << "change sidelength so triangle is off the page in x and y"
		<< endl << " change sideLength to 165";
	cout << ": plotted Yellow" << endl;
	Triangle T23( 470, 695, 100, C7);
	T23.SetDimension1(165);	
	T23.Print();
	T23.Display(myImage, "triangleTestOut.bmp");
	cout << endl << endl << endl;

	cout << "TESTING TRIANGLE DIVIDE" << endl;
	Triangle *TList = NULL;
	TList = new Triangle[3];
	// plot the undivided triangle in blue
	Triangle T19( 330,150,140, C1);
	T19.Display(myImage, "triangleTestOut.bmp");
	cout << "the triangle that will be divided" << endl;
	T19.Print();
	// plot the subtriangles in yellow
	T19.SetShapeColour(C7);
	T19.TriangleDivide ( TList );
	cout << "the list of three subtriangles: Plotted Yellow" << endl;
	for( int i=0; i<3; i++)
	{
		TList[i].Display(myImage, "triangleTestOut.bmp");
		TList[i].Print();
		cout << endl;
	}
	delete [] TList;
	cout << endl << endl << endl;

    cout << "????????????????????????????????????????????????????";


    cout << "BEGIN GASKET TEST" << endl << endl;

    //Gasket test here

    cout << "TESTING CONSTRUCTORS: ON AND OFF PAGE" << endl;
    ResetBackground(myImage, CB, 600, 800);
    cout << endl << "Constructor 4 arguments, xLocation off page:: RED" << endl;
	cout << "create g6" << endl;
    Gasket G6(0, 666, 200, 200, C3);
    G6.Display(myImage, "GasketConstructors.bmp");
    G6.Print();
    cout << endl << endl << endl
		 << "Constructor 4 arguments, yLocation off page:: LIGHT BLUE" << endl;
	cout << "create g8" << endl;
    Gasket G7(0, 100, 888, 150, C5);
    G7.Display(myImage, "GasketConstructors.bmp");
    G7.Print();
    cout << endl << "Default contructor: BLACK" << endl;
	cout <<  "create G1" << endl;
    Gasket G1;
    G1.Display(myImage, "GasketConstructors.bmp");
    G1.Print();
    cout << endl << "Constructor with 4 arguments on page: LIGHT BLUE" << endl;	
	cout << "create G2" << endl;
    Gasket G2(0, 150, 200, 400, C5);
    G2.Display(myImage, "GasketConstructors.bmp");
    G2.Print();
    cout << endl << "Constructor 4 arguments, sidelength (x) beyond edge of page: GREY" << endl;
	cout << "create G3" << endl;
    Gasket G3(1, 350, 480, 300, C4);
    G3.Display(myImage, "GasketConstructors.bmp");
    G3.Print();
    cout << endl << "Constructor 4 arguments, sideLength (y) beyond edge of page: DARK BLUE" << endl;
	cout << "create g5" << endl;
    Gasket G5(1, 250, 700, 200, C1);
    G5.Display(myImage, "GasketConstructors.bmp");
    G5.Print();
    cout << endl << endl << endl;

    cout << "TESTING COPY CONSTRUCTOR" << endl;	
    cout << "gasket to copy" << endl;
    G5.Print();
    Gasket G8(G5);
    cout << "copied gasket" << endl;
    G8.Print();
    cout << endl << endl << endl;

			//Test the < operator
	cout << "testing Gasket < Triangle, answer should be true (1) " <<  (G7 < T5);
	cout << endl;	
	cout << "testing Gasket < Gasket, answer should be true (1) " <<  (G5 < G2);
	cout << endl;
	cout << "testing Gasket < Rectangle, answer should be true (1) " <<  (G6 < R3);
	cout << endl;
	cout << "testing Gasket < Triangle, answer should be false (0) " << (G3 < T6);
	cout << endl;	
	cout << "testing Gasket < Gasket, answer should be false (0) " << (G7 < G1);
	cout << endl;
	cout << "testing Gasket < Rectangle, answer should be false (0) " << (G2 < R7);
	cout << endl << endl << endl;

	//Test the > operator
	cout << "testing Gasket > Triangle, answer should be true (1) " <<  (G3 > T5);
	cout << endl;	
	cout << "testing Gasket > Gasket, answer should be true (1) " <<  ( G2 > G3);
	cout << endl;
	cout << "testing Gasket > Rectangle, answer should be true (1) " <<  (G7 > R19);
	cout << endl;
	cout << "testing Gasket > Triangle, answer should be false (0) " << (G5 > T4);
	cout << endl;	
	cout << "testing Gasket > Gasket, answer should be false (0) " << (G1 > G3);
	cout << endl;
	cout << "testing Gasket > Rectangle, answer should be false (0) " << (G7 > R2);
	cout << G7.Area() << " "  << R2.Area();
	cout << endl << endl << endl;

    ResetBackground(myImage, CB, 600, 800);
    cout << "TESTING MUTATORS" << endl;
    cout << "changing G2 colour light blue to red and iterations" << endl;
    cout << "displayed in red, 1 iteration" << endl;
    G2.SetShapeColour(C3);
    G2.SetIterations(1);
    G2.Display(myImage, "GasketMutators.bmp");
    G2.Print();
    cout << endl << "changing side length of G3 from 300 to 200" << endl;
	cout << "displayed in grey at 350 480" << endl;
    G3.SetDimension1(200);
    G3.Display(myImage, "GasketMutators.bmp");
    G3.Print();
    cout << endl << "changing xlocation and ylocation of G5"<< endl;
	cout << "xlocation to 10 ylocation to 350"  << endl;
	cout << "displayed in dark blue" << endl;
    G5.SetXLocation(10);
    G5.SetYLocation(350);
    G5.Display(myImage, "GasketMutators.bmp");
    G5.Print();	
    cout << "moving yLocation of G2 so gasket is partially off the page" << endl;
    cout << "yLocation set to 575, changing colour to dark blue" << endl;
    G2.SetYLocation( 575 );
    G2.SetShapeColour(C1);
    G2.Display(myImage, "GasketMutators.bmp");
    G2.Print();
    cout << "moving xLocation of G5 to 550 so gasket is partially off the page" << endl;
    cout << "changing colour to light blue" << endl;
    G5.SetShapeColour(C5);
    G5.SetXLocation(550);
    G5.Display(myImage, "GasketMutators.bmp");
    G5.Print();
    cout << "moving xLocation of G2 off the page to 888" << endl;
    G2.SetYLocation( 888);
    G2.Display(myImage, "GasketMutators.bmp");
    G2.Print();
    cout << endl << endl << endl;


    cout << "Producing on page gaskets for 2 to 4 iterations";
    for (int k=2; k <= 5; k++)
    {	
        myFileName="BitFileG";   
        myFileName.append(to_string(k));
        myFileName += ".bmp";
        Gasket G4(k, 50, 200, 500, C2);
        ResetBackground(myImage,C3, 600, 800);
        G4.Display(myImage, myFileName);
    }


	// Testing mixed overlays(280
	Rectangle R51( 280, 225, 30, 50, C2);
	Triangle T51( 240,220,125,C3);
	Gasket G51( 2, 150,180,320, C4);
	Triangle T52( 100,150,425,C5);
	Rectangle R52( 50,50,500,550, C6);
	Triangle T53(110,270, 270,C7);
	Rectangle R53( 300, 320, 140, 160, C8);
	Gasket G53(1, 280, 340, 70, CB);
    Gasket G54(1, 240, 680, 70, C7);
	shapeArray[0] = &R52;
	shapeArray[1] = &T52;
	shapeArray[2] = &T53;
	shapeArray[3] = &R53;
	shapeArray[4] = &G51;
	shapeArray[5] = &T51;
	shapeArray[6] = &R51;
	shapeArray[7] = &G53;
	shapeArray[8] = &G54;

	ResetBackground(myImage,C1, 600, 800);
	for( int i=0; i<9; i++)
	{
		cout << endl << "Element in the array of shapes at index " << i << endl;
		shapeArray[i]->Display(myImage, "Mixed_Overlay_Test.bmp");
		shapeArray[i]->Print();
	}

	cout << endl;
	if(R52.DoesOverlay(&T52))
	{
		cout << "R52 overlays T52" << endl;
	}
	if(R52.DoesOverlay(&G51))
	{
		cout << "R52 overlays G51" << endl;
	}	
	if(R52.DoesOverlay(&T51))
	{
		cout << "R52 overlays T51" << endl;
	}	
	if(R52.DoesOverlay(&R51))
	{
		cout << "R52 overlays R51" << endl;
	}	
	if(R52.DoesOverlay(&T53))
	{
		cout << "R52 overlays T53" << endl;
	}
	if(R52.DoesOverlay(&R53))
	{
		cout << "R52 overlays R53" << endl;
	}	
	if(R52.DoesOverlay(&G53))
	{
		cout << "R52 overlays G53" << endl;
	}	
	if(R52.DoesOverlay(&G54))
	{
		cout << "R52 overlays G54" << endl;
	}
	if(T52.DoesOverlay(&R52))
	{
		cout << "T52 overlays R52" << endl;
	}
	if(T52.DoesOverlay(&G51))
	{
		cout << "T52 overlays G51" << endl;
	}
	if(T52.DoesOverlay(&T51))
	{
		cout << "T52 overlays T51" << endl;
	}
	if(T52.DoesOverlay(&R51))
	{
		cout << "T52 overlays R51" << endl;
	}	
	if(T52.DoesOverlay(&T53))
	{
		cout << "T52 overlays T53" << endl;
	}
	if(T52.DoesOverlay(&R53))
	{
		cout << "T52 overlays R53" << endl;
	}
	if(T52.DoesOverlay(&G53))
	{
		cout << "T52 overlays G53" << endl;
	}
	if(T52.DoesOverlay(&G54))
	{
		cout << "T52 overlays G54" << endl;
	}
	if(G51.DoesOverlay(&R52))
	{
		cout << "G51 overlays R52" << endl;
	}	
	if(G51.DoesOverlay(&T52))
	{
		cout << "G51 overlays T52" << endl;
	}	
	if(G51.DoesOverlay(&T51))
	{
		cout << "G51 overlays T51" << endl;
	}	
	if(G51.DoesOverlay(&R51))
	{
		cout << "G51 overlays R51" << endl;
	}
	if(G51.DoesOverlay(&G54))
	{
	cout << "G51 overlays G54" << endl;
	}	
	if(G51.DoesOverlay(&T53))
	{
		cout << "G51 overlays T52" << endl;
	}	
	if(G51.DoesOverlay(&R53))
	{
		cout << "G51 overlays R53" << endl;
	}	
	if(G51.DoesOverlay(&G53))
	{
		cout << "G51 overlays G53" << endl;
	}
	if(T51.DoesOverlay(&R52))
	{
		cout << "T51 overlays R52" << endl;
	}
	if(T51.DoesOverlay(&T52))
	{
		cout << "T51 overlays T52" << endl;
	}	
	if(T51.DoesOverlay(&G51))
	{
		cout << "T51 overlays G51" << endl;
	}	
	if(T51.DoesOverlay(&R51))
	{
		cout << "T51 overlays R51" << endl;
	}	
	if(T51.DoesOverlay(&G54))
	{
		cout << "T51 overlays G54" << endl;
	}
	if(T51.DoesOverlay(&T53))
	{
		cout << "T51 overlays T53" << endl;
	}	
	if(T51.DoesOverlay(&G53))
	{
		cout << "T51 overlays G53" << endl;
	}	
	if(T51.DoesOverlay(&R53))
	{
		cout << "T51 overlays R53" << endl;
	}	
	if(R51.DoesOverlay(&R52))
	{
		cout << "R51 overlays R52" << endl;
	}	
	if(R51.DoesOverlay(&T52))
	{
		cout << "R51 overlays T52" << endl;
	}	
	if(R51.DoesOverlay(&G51))
	{
		cout << "R51 overlays G51" << endl;
	}	
	if(R51.DoesOverlay(&T51))
	{
		cout << "R51 overlays T51" << endl;
	}
	if(R51.DoesOverlay(&R53))
	{
		cout << "R51 overlays R53" << endl;
	}	
	if(R51.DoesOverlay(&G53))
	{
		cout << "R51 overlays G53" << endl;
	}	
	if(R51.DoesOverlay(&G54))
	{
		cout << "R51 overlays G54" << endl;
	}	
	if(R51.DoesOverlay(&T53))
	{
		cout << "R51 overlays T53" << endl;
	}
	if(T53.DoesOverlay(&R52))
	{
		cout << "T53 overlays R52" << endl;
	}	
	if(T53.DoesOverlay(&T52))
	{
		cout << "T53 overlays T52" << endl;
	}	
	if(T53.DoesOverlay(&G51))
	{
		cout << "T53 overlays G51" << endl;
	}	
	if(T53.DoesOverlay(&T51))
	{
		cout << "T53 overlays T51" << endl;
	}
	if(T53.DoesOverlay(&R51))
	{
		cout << "T53 overlays R51" << endl;
	}	
	if(T53.DoesOverlay(&G53))
	{
		cout << "T53 overlays G53" << endl;
	}	
	if(T53.DoesOverlay(&G54))
	{
		cout << "T53 overlays G54" << endl;
	}	
	if(T53.DoesOverlay(&R53))
	{
		cout << "T53 overlays R53" << endl;
	}
	if(R53.DoesOverlay(&R52))
	{
		cout << "R53 overlays R52" << endl;
	}	
	if(R53.DoesOverlay(&T52))
	{
		cout << "R53 overlays T52" << endl;
	}	
	if(R53.DoesOverlay(&G51))
	{
		cout << "R53 overlays G51" << endl;
	}	
	if(R53.DoesOverlay(&T51))
	{
		cout << "R53 overlays T51" << endl;
	}
	if(R53.DoesOverlay(&R51))
	{
		cout << "R53 overlays R51" << endl;
	}	
	if(R53.DoesOverlay(&G53))
	{
		cout << "R53 overlays G53" << endl;
	}	
	if(R53.DoesOverlay(&G54))
	{
		cout << "R53 overlays G54" << endl;
	}	
	if(R53.DoesOverlay(&T53))
	{
		cout << "R53 overlays T53" << endl;
	}
	if(G53.DoesOverlay(&R52))
	{
		cout << "G53 overlays R52" << endl;
	}	
	if(G53.DoesOverlay(&T52))
	{
		cout << "G53 overlays T52" << endl;
	}	
	if(G53.DoesOverlay(&G51))
	{
		cout << "G53 overlays G51" << endl;
	}	
	if(G53.DoesOverlay(&T51))
	{
		cout << "G53 overlays T51" << endl;
	}
	if(G53.DoesOverlay(&R51))
	{
		cout << "G53 overlays R51" << endl;
	}	
	if(G53.DoesOverlay(&R53))
	{
		cout << "G53 overlays R53" << endl;
	}	
	if(G53.DoesOverlay(&G54))
	{
		cout << "G53 overlays G54" << endl;
	}	
	if(G53.DoesOverlay(&T53))
	{
		cout << "G53 overlays T53" << endl;
	}
	if(G54.DoesOverlay(&R52))
	{
		cout << "G54 overlays R52" << endl;
	}	
	if(G54.DoesOverlay(&T52))
	{
		cout << "G54 overlays T52" << endl;
	}	
	if(G54.DoesOverlay(&G51))
	{
		cout << "G54 overlays G51" << endl;
	}	
	if(G54.DoesOverlay(&T51))
	{
		cout << "G54 overlays T51" << endl;
	}
	if(G54.DoesOverlay(&R51))
	{
		cout << "G54 overlays R51" << endl;
	}	
	if(G54.DoesOverlay(&G53))
	{
		cout << "G54 overlays G53" << endl;
	}	
	if(G54.DoesOverlay(&R53))
	{
		cout << "G54 overlays R53" << endl;
	}	
	if(G54.DoesOverlay(&T53))
	{
		cout << "G54 overlays T53" << endl;
	}
	cout << endl << endl << endl;

	//Testing print thorugh pointers to shapes

	return 0;
}