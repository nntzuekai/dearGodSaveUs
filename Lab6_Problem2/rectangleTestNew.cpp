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
	string fname2;
	Shape* shapeArray[25];

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

	cerr << "TESTING THREE CONSTRUCTORS: Printing R1 (default), R2(3 arg) and R3( 4 arg)" << endl;
	R1.Print();
	cerr << endl;
	R2.Print();
	cerr << endl;
	R3.Print();
	cerr << endl << endl << endl;


	cerr << "TESTING COPY CONSTRUCTOR" << endl;
	cerr << "R4, rectangle to copy" << endl;
	R4.Print();
	cerr << endl << "R6, created with copy constructor " << endl;
	R6.Print();
	cerr << endl << "testing self copy" << endl;
	R6 = Rectangle(R6);

	cerr << endl << endl << endl;


	cerr << "TESTING GETTERS" << endl;
	cerr << "getting values from R6" << endl;
	R6.Print();
	cerr << endl;
	cerr << "Getting Width " << R6.GetDimension1() << endl;
	cerr << "Getting Height " << R6.GetHeight() << endl;
	cerr << "Getting xLocation " << R6.GetXLocation() << endl; 
	cerr << "Getting yLocation " << R6.GetYLocation() << endl;
	cerr << "Getting rectanglesCreated " << R6.GetRectanglesCreated()<< endl;
	cerr << "Getting rectanglesExisting " << R6.GetRectanglesExisting() << endl;
	cerr << "Getting blockColour " << R6.GetShapeColour() << endl;
	cerr << endl << endl << endl;


	cerr << "TESTING SETTERS: changing default values in R1 and R2" << endl;
	cerr << "None of the following 7 changes result in a Rectangle that"  
		<< endl << " is partially or completely off the page" << endl;
	cerr << endl << "R1 before changes" << endl;     
	R1.Print();
	cerr << endl;
	R1.SetDimension1(220);
	cerr << "set R1.width set to 220" << endl;
	R1.SetHeight(100);
	cerr << "set R1.height set to 100" << endl;
	R1.SetXLocation(100);
	cerr << "set R1.xLocation set to 100" << endl;
	R1.SetYLocation(225);
	cerr << "set R1.yLocation set to 225" << endl;
	R1.SetShapeColour(C6);
	cerr << "set R1.Colour set to " << C6 << endl << endl;
	cerr << "modified R1" << endl;
	R1.Print();
	cerr << endl << endl;

	cerr << "R2 before changes" << endl;
	R2.Print();
	cerr << endl;
	cerr << "set R2.height to 280" << endl;
	cerr << "set R2.width to 100" << endl;
	R2.SetHeight(225);
	R2.SetDimension1(100);
	cerr << "modified R2" << endl;
	R2.Print();
	cerr << endl << endl << endl;


	cerr << "TESTING OVERLAY" << endl;
	if(R1.DoesOverlay(&R2))
	{
		cerr << "R1 overlays R2" << endl;
	}
	if(R1.DoesOverlay(&R3))
	{
		cerr << "R1 overlays R3" << endl;
	}
	if(R1.DoesOverlay(&R4))
	{
		cerr << "R1 overlays R4" << endl;
	}
	if(R1.DoesOverlay(&R5))
	{
		cerr << "R1 overlays R5" << endl;
	}
	if(R1.DoesOverlay(&R7))
	{
		cerr << "R1 overlays R7" << endl;
	}
	if(R1.DoesOverlay(&R8))
	{
		cerr << "R1 overlays R8" << endl;
	}
	if(R2.DoesOverlay(&R1))
	{
		cerr << "R2 overlays R1" << endl;
	}
	if(R2.DoesOverlay(&R3))
	{
		cerr << "R2 overlays R3" << endl;
	}
	if(R2.DoesOverlay(&R4))
	{
		cerr << "R2 overlays R4" << endl;
	}
	if(R2.DoesOverlay(&R5))
	{
		cerr << "R2 overlays R5" << endl;
	}
	if(R2.DoesOverlay(&R7))
	{
		cerr << "R2 overlays R7" << endl;
	}
	if(R2.DoesOverlay(&R8))
	{
		cerr << "R2 overlays R8" << endl;
	}
	if(R3.DoesOverlay(&R1))
	{
		cerr << "R3 overlays R1" << endl;
	}
	if(R3.DoesOverlay(&R2))
	{
		cerr << "R3 overlays R2" << endl;
	}
	if(R3.DoesOverlay(&R4))
	{
		cerr << "R3 overlays R4" << endl;
	}
	if(R3.DoesOverlay(&R5))
	{
		cerr << "R3 overlays R5" << endl;
	}
	if(R3.DoesOverlay(&R7))
	{
		cerr << "R3 overlays R7" << endl;
	}
	if(R3.DoesOverlay(&R8))
	{
		cerr << "R3 overlays R8" << endl;
	}
	if(R4.DoesOverlay(&R1))
	{
		cerr << "R4 overlays R1" << endl;
	}
	if(R4.DoesOverlay(&R2))
	{
		cerr << "R4 overlays R2" << endl;
	}
	if(R4.DoesOverlay(&R3))
	{
		cerr << "R4 overlays R3" << endl;
	}	
	if(R4.DoesOverlay(&R5))
	{
		cerr << "R4 overlays R5" << endl;
	}
	if(R4.DoesOverlay(&R7))
	{
		cerr << "R4 overlays R7" << endl;
	}
	if(R4.DoesOverlay(&R8))
	{
		cerr << "R4 overlays R8" << endl;
	}
	if(R5.DoesOverlay(&R1))
	{
		cerr << "R5 overlays R1" << endl;
	}
	if(R5.DoesOverlay(&R2))
	{
		cerr << "R5 overlays R2" << endl;
	}
	if(R5.DoesOverlay(&R3))
	{
		cerr << "R5 overlays R3" << endl;
	}	
	if(R5.DoesOverlay(&R4))
	{
		cerr << "R5 overlays R4" << endl;
	}	
	if(R5.DoesOverlay(&R7))
	{
		cerr << "R5 overlays R7" << endl;
	}	
	if(R5.DoesOverlay(&R8))
	{
		cerr << "R5 overlays R8" << endl;
	}
	if(R7.DoesOverlay(&R1))
	{
		cerr << "R7 overlays R1" << endl;
	}
	if(R7.DoesOverlay(&R2))
	{
		cerr << "R7 overlays R2" << endl;
	}
	if(R7.DoesOverlay(&R3))
	{
		cerr << "R7 overlays R3" << endl;
	}	
	if(R7.DoesOverlay(&R4))
	{
		cerr << "R7 overlays R4" << endl;
	}	
	if(R7.DoesOverlay(&R5))
	{
		cerr << "R7 overlays R5" << endl;
	}	
	if(R7.DoesOverlay(&R8))
	{
		cerr << "R7 overlays R8" << endl;
	}	
	if(R8.DoesOverlay(&R1))
	{
		cerr << "R8 overlays R1" << endl;
	}
	if(R8.DoesOverlay(&R2))
	{
		cerr << "R8 overlays R2" << endl;
	}
	if(R8.DoesOverlay(&R3))
	{
		cerr << "R8 overlays R3" << endl;
	}	
	if(R8.DoesOverlay(&R4))
	{
		cerr << "R8 overlays R4" << endl;
	}	
	if(R8.DoesOverlay(&R5))
	{
		cerr << "R8 overlays R5" << endl;
	}	
	if(R8.DoesOverlay(&R7))
	{
		cerr << "R8 overlays R7" << endl;
	}	
	cerr << endl << endl << endl;


	cerr << "TESTING DISPLAY OF RECTANGLES" << endl;
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

	cerr << endl << endl << endl;

	cerr << "TESTING = OPERATOR"<< endl;
	cerr << "printing R5"<< endl;
	R5.Print();
	cerr << "printing R1" << endl;
	R1.Print();
	R1 = R1;
	cerr << endl;
	cerr << "printing R1 after R1=R1"<< endl;
	R1.Print();
	cerr << endl;
	R1 = R5;
	cerr << endl;
	cerr << "printing R1 after R1=R5"<< endl;
	R1.Print();
	cerr << endl << endl << endl;

	cerr << "TESTING THE << OPERATOR" << endl;
	cerr << "R5" << endl << R5;
	cerr << endl << endl << endl;

	//Test the == operator
	cerr << "Testing == answer should be true (1) " << (R1==R5);
	cerr << endl;
	cerr << "Testing == answer should be false (0) " << (R3==R1);
	cerr << endl << endl << endl;

	//Test the < operator
	cerr << "testing Rectangle < Triangle, answer should be true (1) " <<  (R7 < TC1);
	cerr << endl;	
	cerr << "testing Rectangle < Gasket, answer should be true (1) " <<  (R5 < GC1);
	cerr << endl;
	cerr << "testing Rectangle < Rectangle, answer should be true (1) " <<  (R3 < R4);
	cerr << endl;
	cerr << "testing Rectangle < Triangle, answer should be false (0) " << (R3 < TC2);
	cerr << endl;	
	cerr << "testing Rectangle < Gasket, answer should be false (0) " << (R4 < GC2);
	cerr << endl;
	cerr << "testing Rectangle < Rectangle, answer should be false (0) " << (R4 < R2);
	cerr << endl << endl << endl;

	//Test the > operator
	cerr << "testing Rectangle > Triangle, answer should be true (1) " <<  (R4 > TC1);
	cerr << endl;	
	cerr << "testing Rectangle > Gasket, answer should be true (1) " <<  (R4 > GC2);
	cerr << endl;
	cerr << "testing Rectange > Rectangle, answer should be true (1) " <<  (R4 > R5);
	cerr << endl;
	cerr << "testing Rectangle > Triangle, answer should be false (0) " << (R3 > TC1);
	cerr << endl;	
	cerr << "testing Rectangle > Gasket, answer should be false (0) " << (R1 > GC1);
	cerr << endl;
	cerr << "testing Rectangle > Rectangle, answer should be false (0) " << (R7 > R8);
	cerr << endl << endl << endl;

	cerr << "TESTING RECTANGLES OVERLAPPING EDGES OF PAGE" << endl;
	ResetBackground(myImage, CB, 600, 800);

	cerr << "RECTANGLE BOTH xLocation AND yLocation OFF THE PAGE";
	cerr << ": plotted Red" << endl;
	Rectangle R10( -5, 990, 300, 250, C3 );
	cerr << endl;
	R10.Display(myImage, "rectangleTestOut.bmp");
	R10.Print();	

	cerr << endl << "RECTANGLE, yLocation OFF THE PAGE";
	cerr << ": plotted Black" << endl;	
	Rectangle R11( 100, 977, 200, 200, C2);
	cerr << endl;
	R11.Display(myImage, "rectangleTestOut.bmp");
	R11.Print();

	cerr << endl << "RECTANGLE, xLocation OFF THE PAGE";
	cerr << ": plotted dark Blue" << endl;	
	Rectangle R12( 800, 100, 140, 150, C1); 
	cerr << endl;
	R12.Display(myImage, "rectangleTestOut.bmp");
	R12.Print();

	cerr << endl << "RECTANGLE, xLocation ON PAGE, xLocation+width OFF THE PAGE";
	cerr << ": plotted Pink" << endl;
	Rectangle R13( 450, 150, 300,200, C6);
	cerr << endl;
	R13.Display(myImage, "rectangleTestOut.bmp");
	R13.Print();
	cerr << endl << "move x off page, change colour" << endl;
	R13.SetXLocation(500);


	cerr << endl << "RECTANGLE, yLocation ON PAGE, yLocation+height OFF THE PAGE";
	cerr << ": plotted Light Blue" << endl;
	Rectangle R14( 277, 688, 175, 220, C8);
	cerr << endl;
	R14.Display(myImage, "rectangleTestOut.bmp");
	R14.Print();

	cerr << endl << "RECTANGLE, xLocation ON PAGE, xLocation+width OFF THE PAGE";
	cerr << endl << "RECTANGLE, yLocation ON PAGE, yLocation+height OFF THE PAGE";
	cerr << ": plotted Grey" << endl;
	Rectangle R15( 522, 553, 128, 300, C4);
	cerr << endl;
	R15.Display(myImage, "rectangleTestOut.bmp");
	R15.Print();

	cerr << endl << "mutator for x value moves partially off page";
	cerr << endl << "mutator for y value moves partially off page";
	cerr  << endl << "x moved to 580,  y moved to 700";
	cerr << ": plotted Yellow" << endl;
	Rectangle R19( 500, 450, 80, 340, C4);
	R19.SetShapeColour(C7);
	R19.SetXLocation(580);
	R19.SetYLocation(700);
	R19.Display(myImage, "rectangleTestOut.bmp");
	R19.Print();
	cerr << endl;
	R19.Display(myImage, "rectangleTestOut.bmp");
	R19.Print();

	cerr << endl << "mutator for x value moves partially off page";
	cerr  << endl << "x moved to 480";
	cerr << ": plotted Dark Blue" << endl;
	Rectangle R16( 50, 0, 140, 150, C1);
	R16.SetXLocation(580);
	R16.Display(myImage, "rectangleTestOut.bmp");
	R16.Print();

	cerr << endl << "mutator for y value moves partially off page";
	cerr  << endl << "y moved to 670";
	cerr << ": plotted Black" << endl;
	Rectangle R17( 0, 0, 100, 200, C2);
	R17.SetYLocation(670);
	R17.Display(myImage, "rectangleTestOut.bmp");
	R17.Print();

	cerr << endl << "mutator for width value moves partially off page";
	cerr  << endl << "width moved to 370";
	cerr << ": plotted Purple" << endl;
	Rectangle R18( 440, 400, 100, 120, C8);
	R18.SetDimension1(370);
	R18.Display(myImage, "rectangleTestOut.bmp");
	R18.Print();

	cerr << endl << "mutator for height value moves partially off page";
	cerr  << endl << "height moved to 370";
	cerr << ": plotted Red" << endl;
	Rectangle R20( 110, 600, 100, 120, C7);
	R20.SetHeight(250);
	R20.Display(myImage, "rectangleTestOut.bmp");
	R20.Print();

	cerr << endl << endl << endl;
	cerr << "????????????????????????????????????????????????????";


	cerr << "BEGIN TRIANGLE TEST" << endl << endl;
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


	cerr << "TESTING THREE CONSTRUCTORS: Printing T1(default), T2(3arg) and T3(4arg)" << endl;
	cerr << "ALSO TESTING PRINT FUNCTION" << endl;
	ResetBackground(myImage, CB, 600, 800);
	T1.Print();
	cerr << endl;
	T2.Print();
	cerr << endl;
	T3.Print();
	cerr << endl << endl << endl;


	cerr << "TESTING COPY CONSTRUCTOR" << endl;	
	cerr << "Triangle to copy" << endl;
	T2.Print();
	cerr << "Triangle created with copy constructor" << endl;
	T6.Print();
	cerr << endl << endl << endl;


	cerr << "TESTING GETTERS" << endl;    
	cerr << "getting values from T6" << endl;
	T6.Print();
	cerr << endl;
	cerr << "Getting Width " << T6.GetDimension1() << endl;
	cerr << "Getting xLocation " << T6.GetXLocation() << endl; 
	cerr << "Getting yLocation " << T6.GetYLocation() << endl;
	cerr << "Getting trianglesCreated " << T6.GetTrianglesCreated()<< endl;
	cerr << "Getting trianglesExisting " << T6.GetTrianglesExisting() << endl;
	cerr << "Getting blockColour " << T6.GetShapeColour() << endl;
	cerr << endl << endl << endl;


	cerr << "TESTING SETTERS: changing default values in T1 and T2" << endl;
	cerr << "None of the following 6 changes result in a Triangle that"  
		<< endl << " is partially or completely off the page" << endl;
	cerr << endl << "T1 before changes" << endl; 
	T1.Print();
	cerr << endl;
	cerr << "setting R1.sideLength to 330" << endl;
	T1.SetDimension1(330);
	cerr << "setting R1.xLocation to 25"  << endl;
	T1.SetXLocation(25);
	cerr << "setting R1.yLocation to 480"  << endl;
	T1.SetYLocation(480);
	cerr << "setting R1.TriangleColour to C7" << endl;
	T1.SetShapeColour(C7);
	cerr << "modified R1" << endl;
	T1.Print();
	cerr << endl;
	cerr << "T2 before changes" << endl;
	T2.Print();
	cerr << endl << "setting sideLength to 50" << endl;
	T2.SetDimension1(210);
	T6.SetDimension1(210);
	cerr << "modified R2" << endl;
	T2.Print();
	cerr << endl << endl << endl;


	cerr << "TESTING DISPLAY OF TRIANGLES" << endl;
	T4.Display(myImage, "triangleTest.bmp");
	T3.Display(myImage, "triangleTest.bmp");
	T5.Display(myImage, "triangleTest.bmp");
	T1.Display(myImage, "triangleTest.bmp");
	T2.Display(myImage, "triangleTest.bmp");
	T6.Display(myImage, "triangleTest.bmp");
	cerr << endl << endl << endl;

	cerr << "TESTING OVERLAY" << endl;
	if(T1.DoesOverlay(&T2))
	{
		cerr << "T1 overlays T2" << endl;
	}
	if(T1.DoesOverlay(&T3))
	{
		cerr << "T1 overlays T3" << endl;
	}
	if(T1.DoesOverlay(&T4))
	{
		cerr << "T1 overlays T4" << endl;
	}
	if(T1.DoesOverlay(&T5))
	{
		cerr << "T1 overlays T5" << endl;
	}
	if(T1.DoesOverlay(&T6))
	{
		cerr << "T1 overlays T6" << endl;
	}
	if(T2.DoesOverlay(&T1))
	{
		cerr << "T2 overlays T1" << endl;
	}
	if(T2.DoesOverlay(&T3))
	{
		cerr << "T2 overlays T3" << endl;
	}
	if(T2.DoesOverlay(&T4))
	{
		cerr << "T2 overlays T4" << endl;
	}
	if(T2.DoesOverlay(&T5))
	{
		cerr << "T2 overlays T5" << endl;
	}
	if(T2.DoesOverlay(&T6))
	{
		cerr << "T2 overlays T6" << endl;
	}
	if(T3.DoesOverlay(&T1))
	{
		cerr << "T3 overlays T1" << endl;
	}
	if(T3.DoesOverlay(&T2))
	{
		cerr << "T3 overlays T2" << endl;
	}
	if(T3.DoesOverlay(&T4))
	{
		cerr << "T3 overlays T4" << endl;
	}
	if(T3.DoesOverlay(&T5))
	{
		cerr << "T3 overlays T5" << endl;
	}
	if(T3.DoesOverlay(&T6))
	{
		cerr << "T3 overlays T6" << endl;
	}
	if(T4.DoesOverlay(&T1))
	{
		cerr << "T4 overlays T1" << endl;
	}
	if(T4.DoesOverlay(&T2))
	{
		cerr << "T4 overlays T2" << endl;
	}
	if(T4.DoesOverlay(&T3))
	{
		cerr << "T4 overlays T3" << endl;
	}	
	if(T4.DoesOverlay(&T5))
	{
		cerr << "T4 overlays T5" << endl;
	}
	if(T4.DoesOverlay(&T6))
	{
		cerr << "T4 overlays T5" << endl;
	}
	if(T5.DoesOverlay(&T1))
	{
		cerr << "T5 overlays T1" << endl;
	}
	if(T5.DoesOverlay(&T2))
	{
		cerr << "T5 overlays T2" << endl;
	}
	if(T5.DoesOverlay(&T3))
	{
		cerr << "T5 overlays T3" << endl;
	}	
	if(T5.DoesOverlay(&T4))
	{
		cerr << "T5 overlays T4" << endl;
	}	
	if(T5.DoesOverlay(&T6))
	{
		cerr << "T5 overlays T6" << endl;
	}	    
	if(T6.DoesOverlay(&T1))
	{
		cerr << "T6 overlays T1" << endl;
	}
	if(T6.DoesOverlay(&T2))
	{
		cerr << "T6 overlays T2" << endl;
	}
	if(T6.DoesOverlay(&T3))
	{
		cerr << "T6 overlays T3" << endl;
	}	
	if(T6.DoesOverlay(&T4))
	{
		cerr << "T6 overlays T4" << endl;
	}	
	if(T6.DoesOverlay(&T5))
	{
		cerr << "T6 overlays T5" << endl;
	}	
	cerr << endl << endl << endl;

	cerr << "TESTING = OPERATOR"<< endl;
	cerr << "printing T3"<< endl;
	T3.Print();
	cerr << "printing T4" << endl;
	T4.Print();
	cerr << endl;
	cerr << "printing T4 after T4=T3"<< endl;
	T4 = T3;
	T4.Print();
	cerr << endl << endl << endl;

	cerr << "TESTING THE << OPERATOR" << endl;
	cerr << "T5" << endl << T5;
	cerr << endl << endl << endl;

	//Test the == operator
	cerr << "Testing == answer should be true (1) " << (T3==T4);
	cerr << endl;
	cerr << "Testing == answer should be false (0) " << (T3==T1);
	cerr << endl << endl << endl;

	//Test the < operator
	cerr << "testing Triangle < Triangle, answer should be true (1) " <<  (T6 < T3);
	cerr << endl;	
	cerr << "testing Triangle < Gasket, answer should be true (1) " <<  (T5 < GC1);
	cerr << endl;
	cerr << "testing Triangle < Rectangle, answer should be true (1) " <<  (T3 < R6);
	cerr << endl;
	cerr << "testing Triangle < Triangle, answer should be false (0) " << (T1 < T3);
	cerr << endl;	
	cerr << "testing Triangle < Gasket, answer should be false (0) " << (T4 < GC2);
	cerr << endl;
	cerr << "testing Triangle < Rectangle, answer should be false (0) " << (T1 < R7);
	cerr << endl << endl << endl;

	//Test the > operator
	cerr << "testing Triangle > Triangle, answer should be true (1) " <<  (T4 > T2);
	cerr << endl;	
	cerr << "testing Triangle > Gasket, answer should be true (1) " <<  (T6 > GC2);
	cerr << endl;
	cerr << "testing Triangle > Rectangle, answer should be true (1) " <<  (T4 > R2);
	cerr << endl;
	cerr << "testing Triangle > Triangle, answer should be false (0) " << (T5 > T6);
	cerr << endl;	
	cerr << "testing Triangle > Gasket, answer should be false (0) " << (T1 > GC1);
	cerr << endl;
	cerr << "testing Triangle > Rectangle, answer should be false (0) " << (T2 > R7);
	cerr << endl << endl << endl;


	cerr << endl << "TESTING TRIANGLES OVERLAPPING EDGES OF PAGE" << endl << endl;
	cerr << "AND TESTING TRIANGLES OUTSIDE THE PAGE" << endl;
	ResetBackground(myImage, CB, 600, 800);
	cerr << "TRIANGLE BOTH xLocation AND yLocation OFF THE PAGE";
	cerr << ": plotted Red" << endl << endl;
	Triangle T10( -20, -100, 400, C3 );
	cerr << endl << endl;
	T10.Display(myImage, "triangleTestOut.bmp");
	T10.Print();
	cerr << endl << "TRIANGLE, yLocation OFF THE PAGE";
	cerr << ": plotted Black" << endl << endl;;
	Triangle T11( 140, 900, 300, C2);
	cerr << endl << endl;
	T11.Display(myImage, "triangleTestOut.bmp");
	T11.Print();
	cerr << endl << "TRIANGLE, xLocation OFF THE PAGE";
	cerr << ": plotted Grey" << endl << endl;
	Triangle T12( 700, 400, 200, C4); 
	cerr << endl;
	T12.Display(myImage, "triangleTestOut.bmp");	
	T12.Print();
	cerr << endl << "TRIANGLE, xLocation ON PAGE, xLocation+width OFF THE PAGE";
	cerr << ": plotted Dark Blue" << endl << endl;
	Triangle T13( 400, 50, 250, C1);
	cerr << endl << endl;
	T13.Display(myImage, "triangleTestOut.bmp");
	T13.Print();
	cerr << endl << "TRIANGLE, yLocation ON PAGE, yLocation+height OFF THE PAGE";
	cerr << ": plotted Grey" << endl << endl;
	Triangle T14( 180, 550, 410, C4);
	cerr << endl << endl;
	T14.Display(myImage, "triangleTestOut.bmp");
	T14.Print();
	cerr << endl << "TRIANGLE, xLocation ON PAGE, xLocation+sideLength OFF THE PAGE";
	cerr << endl << "TRIANGLE, yLocation ON PAGE, yLocation+height OFF THE PAGE";
	cerr << endl << "TRIANGLE, yLocation+height off page after scaling for x";
	cerr << ": plotted Pink" << endl;
	Triangle T15( 350, 600, 330, C6);
	cerr << endl;
	T15.Print();
	T15.Display(myImage, "triangleTestOut.bmp");
	cerr << endl << "TRIANGLE, xLocation ON PAGE, xLocation+sideLength OFF THE PAGE";
	cerr << endl << "TRIANGLE, yLocation ON PAGE, yLocation+height OFF THE PAGE";
	cerr << endl << "TRIANGLE, yLocation+height on page after scaling for x";
	cerr << ": plotted Light Blue" << endl << endl;
	Triangle T16( 300,300,400, C5);
	cerr << endl << endl;
	T16.Display(myImage, "triangleTestOut.bmp");
	T16.Print();

	// TEST MUTATORS Moving off the page
	cerr << "Mutators moving the shape completely or partially off the page" << endl
		<< endl;
	cerr << "TRIANGLE: move triangle so xLocation=650, off page";
	cerr << ": plotted yellow at 0,0" << endl << endl;
	Triangle T17( 420, 400, 120, C7);
	T17.SetXLocation(650); 
	T17.Display(myImage, "triangleTestOut.bmp");
	T17.Print();
	cerr << endl << endl;

	cerr << endl << "move triangle so triangle in y so it is partially off the page"
		<< endl << " change ylocation to 530 ";
	cerr << ": plotted Purple" << endl << endl;
	Triangle T18( 50, 350, 330, C8);
	T18.SetYLocation(530);
	T18.Print();
	T18.Display(myImage, "triangleTestOut.bmp");
	cerr << endl << endl << endl;

	cerr << endl << "change sidelength so triangle is off the page in y"
		<< endl << " change sideLength to 165" << endl << "TRIANGLE: move T15, change sideLength so off page in y";
	cerr << endl << ": plotted Black" << endl;
	Triangle T20( 50, 675, 100, C2);
	T20.SetDimension1(165);	cerr << endl;
	T20.Print();
	T20.Display(myImage, "triangleTestOut.bmp");
	cerr << endl << endl << endl;

	cerr << endl << "move triangle so triangle in x so it is partially off the page"
		<< endl << " change xlocation to 510 " ;
	cerr <<  ": plotted Red" << endl;
	Triangle T21( 450, 230, 130, C3);
	T21.SetXLocation(510);	
	T21.Print();
	T21.Display(myImage, "triangleTestOut.bmp");
	cerr << endl << endl << endl;

	cerr << endl << "change sidelength so triangle is off the page in x"
		<< endl << " change sideLength to 165";
	cerr << ": plotted Purple" << endl;
	Triangle T22( 470, 475, 100, C8);
	T22.SetDimension1(165);	
	T22.Print();
	T22.Display(myImage, "triangleTestOut.bmp");

	cerr << endl << "change sidelength so triangle is off the page in x and y"
		<< endl << " change sideLength to 165";
	cerr << ": plotted Yellow" << endl;
	Triangle T23( 470, 695, 100, C7);
	T23.SetDimension1(165);	
	T23.Print();
	T23.Display(myImage, "triangleTestOut.bmp");
	cerr << endl << endl << endl;

	cerr << "TESTING TRIANGLE DIVIDE" << endl;
	Triangle *TList = NULL;
	TList = new Triangle[3];
	// plot the undivided triangle in blue
	Triangle T19( 330,150,140, C1);
	T19.Display(myImage, "triangleTestOut.bmp");
	cerr << "the triangle that will be divided" << endl;
	T19.Print();
	// plot the subtriangles in yellow
	T19.SetShapeColour(C7);
	T19.TriangleDivide ( TList );
	cerr << "the list of three subtriangles: Plotted Yellow" << endl;
	for( int i=0; i<3; i++)
	{
		TList[i].Display(myImage, "triangleTestOut.bmp");
		TList[i].Print();
		cerr << endl;
	}
	delete [] TList;
	cerr << endl << endl << endl;

    cerr << "????????????????????????????????????????????????????";


    cerr << "BEGIN GASKET TEST" << endl << endl;

    cerr << "TESTING CONSTRUCTORS: ON AND OFF PAGE" << endl;
    ResetBackground(myImage, CB, 600, 800);
    cerr << endl << "Constructor 4 arguments, xLocation off page:: RED" << endl;
	cerr << "create g6" << endl;
    Gasket G6(2, 606, 300, 480, C3);
    G6.Display(myImage, "GasketConstructors.bmp");
    G6.Print();
    cerr << endl << "Constructor 4 arguments, yLocation off page:: LIGHT BLUE" << endl;
	cerr << "create g7" << endl;
    Gasket G7(0, 300, 811, 321, C5);
    G7.Display(myImage, "GasketConstructors.bmp");
    G7.Print();
    cerr << endl << "Contructor with 4 arguments x and y off page: YELLOW" << endl;
	cerr << "create G1" << endl;
    Gasket G0(1, -1, -1, 270, C7);
	G0.Display(myImage, "GasketConstructors.bmp");
	G0.Print();
	cerr << "create G0" << endl;
	cerr << endl << "Default constructor: BLACK" << endl;
	Gasket G1;
    G1.Display(myImage, "GasketConstructors.bmp");
    G1.Print();
    cerr << endl << "Constructor with 4 arguments on page: PURPLE" << endl;	
	cerr << "create G2" << endl;
    Gasket G2(0, 50, 480, 340, C8);
    G2.Display(myImage, "GasketConstructors.bmp");
    G2.Print();
    cerr << endl << "Constructor 4 arguments, sidelength (x) beyond edge of page: GREY" << endl;
	cerr << "create G3" << endl;
    Gasket G3(1, 350, 330, 280, C4);
    G3.Display(myImage, "GasketConstructors.bmp");
    G3.Print();
    cerr << endl << "Constructor 4 arguments, sideLength (y) beyond edge of page: DARK BLUE" << endl;
	cerr << "create g5" << endl;
    Gasket G5(1, 40, 700, 200, C1);
    G5.Display(myImage,  "GasketConstructors.bmp");
    G5.Print();
	cerr << endl << "Constructor 4 argument x and y beyond edge of page: X correction only: YELLOW" << endl;   
	cerr << "create G8" << endl;
	Gasket G8( 1, 400, 600, 300, C7);
	G8.Display(myImage, "GasketConstructors.bmp" );
	G8.Print();
	cerr << endl << endl << endl;
	cerr << endl << "Constructor 4 argument x and y beyond edge of page: X correction only: GREY" << endl;   
	cerr << "create G9" << endl;
	Gasket G9( 1, 400, 700, 300, C4);
	G9.Display(myImage, "GasketConstructors.bmp" );
	G9.Print();
	cerr << endl << endl << endl;

    cerr << "TESTING COPY CONSTRUCTOR" << endl;	
    cerr << "gasket to copy" << endl;
    G5.Print();
    Gasket G10(G5);
    cerr << "copied gasket" << endl;
    G10.Print();
    cerr << endl << endl << endl;

	// Test the << operator

	cerr << "testing the << operator"<< endl;
	cerr << G8;
	cerr << endl << endl << endl;


	//Test the < operator
	cerr << "testing Gasket < Triangle, answer should be true (1) " <<  (G7 < T10);
	cerr << endl;	
	cerr << "testing Gasket < Gasket, answer should be true (1) " <<  (G5 < G2);
	cerr << endl;
	cerr << "testing Gasket < Rectangle, answer should be true (1) " <<  (G6 < R4);
	cerr << endl;
	cerr << "testing Gasket < Triangle, answer should be false (0) " << (G3 < T6);
	cerr << endl;	
	cerr << "testing Gasket < Gasket, answer should be false (0) " << (G7 < G1);
	cerr << endl;
	cerr << "testing Gasket < Rectangle, answer should be false (0) " << (G2 < R7);
	cerr << endl << endl << endl;

	//Test the > operator
	cerr << "testing Gasket > Triangle, answer should be true (1) " <<  (G3 > T5);
	cerr << endl;	
	cerr << "testing Gasket > Gasket, answer should be true (1) " <<  ( G2 > G3);
	cerr << endl;
	cerr << "testing Gasket > Rectangle, answer should be true (1) " <<  (G7 > R19);
	cerr << endl;
	cerr << "testing Gasket > Triangle, answer should be false (0) " << (G5 > T4);
	cerr << endl;	
	cerr << "testing Gasket > Gasket, answer should be false (0) " << (G1 > G3);
	cerr << endl;
	cerr << "testing Gasket > Rectangle, answer should be false (0) " << (G7 > R4);
	cerr << endl << endl << endl;



	ResetBackground(myImage, CB, 600, 800);
    cerr << endl << "changing side length of G0 from 270 to 150: ";
	cerr << " :displayed in YELLOW" << endl;
    G0.SetDimension1(150);
    G0.Display(myImage, "GasketMutators.bmp");
    G0.Print();
    cerr << endl << "changing xlocation and ylocation of G1"<< endl;
	cerr << "xlocation to 150 ylocation to 200: "  << endl;
	cerr << "displayed in BLACK" << endl;
    G1.SetXLocation(100);
    G1.SetYLocation(200);
    G1.Display(myImage, "GasketMutators.bmp");
    G1.Print();	
    cerr << "moving y location of G7 so gasket is partially off the page" << endl;
    cerr << "yLocation set to 675: displayed in LIGHT BLUE" << endl;
    G7.SetYLocation( 675 );
    G7.Display(myImage, "GasketMutators.bmp");
    G7.Print();
	cerr << "moving y location of G7 and increasing sideLength" << endl;
    cerr << "yLocation set to 575 sideLength to 300: displayed in LIGHT BLUE" << endl;
    G7.SetYLocation( 575 );
	G7.SetDimension1(300);
    G7.Display(myImage, "GasketMutators.bmp");
    G7.Print();
	cerr << "TESTING MUTATORS" << endl;
    cerr << "changing G2 colour from light blue: ";
    cerr << "displayed in RED" << endl;
    G2.SetShapeColour(C3);
    G2.Display(myImage,  "GasketMutators.bmp");
    G2.Print();
    cerr << "changing G2 number of iterations from 1 to 3: " ;
    cerr << "displayed in YELLOW" << endl;
    G2.SetShapeColour(C7);
    G2.SetIterations(3);
    G2.Display(myImage, "GasketMutators.bmp");
    G2.Print();
    cerr << "moving xLocation of G6 so gasket is partially off the page" << endl;
    cerr << "xLocaton set to 300: displayed in RED" << endl;
    G6.SetXLocation(300);
    G6.Display(myImage, "GasketMutators.bmp");
    G6.Print();
	cerr << "moving yLocation of G6 to 250, changing colour: " << endl;
    cerr << " displayed in DARK BLUE" << endl;
    G6.SetYLocation(250);
	G6.SetShapeColour(C1);
    G6.Display(myImage, "GasketMutators.bmp");
    G6.Print();
	cerr << "moving yLocation of G6 to 375, changing iterations to 0: " << endl;
    cerr << " displayed in DARK BLUE" << endl;
    G6.SetYLocation(375);
	G6.SetIterations(0);
    G6.Display(myImage, "GasketMutators.bmp");
    G6.Print();
	cerr << "moving yLocation of G6 to 675, xLocation to 475: " << endl;
    cerr << " displayed in DARK BLUE" << endl;
    G6.SetYLocation(675);
	G6.SetXLocation(375);
    G6.Display(myImage, "GasketMutators.bmp");
    G6.Print();
	cerr << endl << endl << endl;

    cerr << "Producing on page gaskets for 2 to 4 iterations";
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
		cerr << endl << "Element in the array of shapes at index " << i << endl;
		shapeArray[i]->Display(myImage, "Mixed_Overlay_Test.bmp");
		shapeArray[i]->Print();
	}

	cerr << endl;
	if(R52.DoesOverlay(&T52))
	{
		cerr << "R52 overlays T52" << endl;
	}
	if(R52.DoesOverlay(&G51))
	{
		cerr << "R52 overlays G51" << endl;
	}	
	if(R52.DoesOverlay(&T51))
	{
		cerr << "R52 overlays T51" << endl;
	}	
	if(R52.DoesOverlay(&R51))
	{
		cerr << "R52 overlays R51" << endl;
	}	
	if(R52.DoesOverlay(&T53))
	{
		cerr << "R52 overlays T53" << endl;
	}
	if(R52.DoesOverlay(&R53))
	{
		cerr << "R52 overlays R53" << endl;
	}	
	if(R52.DoesOverlay(&G53))
	{
		cerr << "R52 overlays G53" << endl;
	}	
	if(R52.DoesOverlay(&G54))
	{
		cerr << "R52 overlays G54" << endl;
	}
	if(T52.DoesOverlay(&R52))
	{
		cerr << "T52 overlays R52" << endl;
	}
	if(T52.DoesOverlay(&G51))
	{
		cerr << "T52 overlays G51" << endl;
	}
	if(T52.DoesOverlay(&T51))
	{
		cerr << "T52 overlays T51" << endl;
	}
	if(T52.DoesOverlay(&R51))
	{
		cerr << "T52 overlays R51" << endl;
	}	
	if(T52.DoesOverlay(&T53))
	{
		cerr << "T52 overlays T53" << endl;
	}
	if(T52.DoesOverlay(&R53))
	{
		cerr << "T52 overlays R53" << endl;
	}
	if(T52.DoesOverlay(&G53))
	{
		cerr << "T52 overlays G53" << endl;
	}
	if(T52.DoesOverlay(&G54))
	{
		cerr << "T52 overlays G54" << endl;
	}
	if(G51.DoesOverlay(&R52))
	{
		cerr << "G51 overlays R52" << endl;
	}	
	if(G51.DoesOverlay(&T53))
	{
		cerr << "G51 overlays T53" << endl;
	}	
	if(G51.DoesOverlay(&T51))
	{
		cerr << "G51 overlays T51" << endl;
	}	
	if(G51.DoesOverlay(&R51))
	{
		cerr << "G51 overlays R51" << endl;
	}
	if(G51.DoesOverlay(&G54))
	{
	cerr << "G51 overlays G54" << endl;
	}	
	if(G51.DoesOverlay(&T52))
	{
		cerr << "G51 overlays T52" << endl;
	}	
	if(G51.DoesOverlay(&R53))
	{
		cerr << "G51 overlays R53" << endl;
	}	
	if(G51.DoesOverlay(&G53))
	{
		cerr << "G51 overlays G53" << endl;
	}
	if(T51.DoesOverlay(&R52))
	{
		cerr << "T51 overlays R52" << endl;
	}
	if(T51.DoesOverlay(&T52))
	{
		cerr << "T51 overlays T52" << endl;
	}	
	if(T51.DoesOverlay(&G51))
	{
		cerr << "T51 overlays G51" << endl;
	}	
	if(T51.DoesOverlay(&R51))
	{
		cerr << "T51 overlays R51" << endl;
	}	
	if(T51.DoesOverlay(&G54))
	{
		cerr << "T51 overlays G54" << endl;
	}
	if(T51.DoesOverlay(&T53))
	{
		cerr << "T51 overlays T53" << endl;
	}	
	if(T51.DoesOverlay(&G53))
	{
		cerr << "T51 overlays G53" << endl;
	}	
	if(T51.DoesOverlay(&R53))
	{
		cerr << "T51 overlays R53" << endl;
	}	
	if(R51.DoesOverlay(&R52))
	{
		cerr << "R51 overlays R52" << endl;
	}	
	if(R51.DoesOverlay(&T52))
	{
		cerr << "R51 overlays T52" << endl;
	}	
	if(R51.DoesOverlay(&G51))
	{
		cerr << "R51 overlays G51" << endl;
	}	
	if(R51.DoesOverlay(&T51))
	{
		cerr << "R51 overlays T51" << endl;
	}
	if(R51.DoesOverlay(&R53))
	{
		cerr << "R51 overlays R53" << endl;
	}	
	if(R51.DoesOverlay(&G53))
	{
		cerr << "R51 overlays G53" << endl;
	}	
	if(R51.DoesOverlay(&G54))
	{
		cerr << "R51 overlays G54" << endl;
	}	
	if(R51.DoesOverlay(&T53))
	{
		cerr << "R51 overlays T53" << endl;
	}
	if(T53.DoesOverlay(&R52))
	{
		cerr << "T53 overlays R52" << endl;
	}	
	if(T53.DoesOverlay(&T52))
	{
		cerr << "T53 overlays T52" << endl;
	}	
	if(T53.DoesOverlay(&G51))
	{
		cerr << "T53 overlays G51" << endl;
	}	
	if(T53.DoesOverlay(&T51))
	{
		cerr << "T53 overlays T51" << endl;
	}
	if(T53.DoesOverlay(&R51))
	{
		cerr << "T53 overlays R51" << endl;
	}	
	if(T53.DoesOverlay(&G53))
	{
		cerr << "T53 overlays G53" << endl;
	}	
	if(T53.DoesOverlay(&G54))
	{
		cerr << "T53 overlays G54" << endl;
	}	
	if(T53.DoesOverlay(&R53))
	{
		cerr << "T53 overlays R53" << endl;
	}
	if(R53.DoesOverlay(&R52))
	{
		cerr << "R53 overlays R52" << endl;
	}	
	if(R53.DoesOverlay(&T52))
	{
		cerr << "R53 overlays T52" << endl;
	}	
	if(R53.DoesOverlay(&G51))
	{
		cerr << "R53 overlays G51" << endl;
	}	
	if(R53.DoesOverlay(&T51))
	{
		cerr << "R53 overlays T51" << endl;
	}
	if(R53.DoesOverlay(&R51))
	{
		cerr << "R53 overlays R51" << endl;
	}	
	if(R53.DoesOverlay(&G53))
	{
		cerr << "R53 overlays G53" << endl;
	}	
	if(R53.DoesOverlay(&G54))
	{
		cerr << "R53 overlays G54" << endl;
	}	
	if(R53.DoesOverlay(&T53))
	{
		cerr << "R53 overlays T53" << endl;
	}
	if(G53.DoesOverlay(&R52))
	{
		cerr << "G53 overlays R52" << endl;
	}	
	if(G53.DoesOverlay(&T52))
	{
		cerr << "G53 overlays T52" << endl;
	}	
	if(G53.DoesOverlay(&G51))
	{
		cerr << "G53 overlays G51" << endl;
	}	
	if(G53.DoesOverlay(&T51))
	{
		cerr << "G53 overlays T51" << endl;
	}
	if(G53.DoesOverlay(&R51))
	{
		cerr << "G53 overlays R51" << endl;
	}	
	if(G53.DoesOverlay(&R53))
	{
		cerr << "G53 overlays R53" << endl;
	}	
	if(G53.DoesOverlay(&G54))
	{
		cerr << "G53 overlays G54" << endl;
	}	
	if(G53.DoesOverlay(&T53))
	{
		cerr << "G53 overlays T53" << endl;
	}
	if(G54.DoesOverlay(&R52))
	{
		cerr << "G54 overlays R52" << endl;
	}	
	if(G54.DoesOverlay(&T52))
	{
		cerr << "G54 overlays T52" << endl;
	}	
	if(G54.DoesOverlay(&G51))
	{
		cerr << "G54 overlays G51" << endl;
	}	
	if(G54.DoesOverlay(&T51))
	{
		cerr << "G54 overlays T51" << endl;
	}
	if(G54.DoesOverlay(&R51))
	{
		cerr << "G54 overlays R51" << endl;
	}	
	if(G54.DoesOverlay(&G53))
	{
		cerr << "G54 overlays G53" << endl;
	}	
	if(G54.DoesOverlay(&R53))
	{
		cerr << "G54 overlays R53" << endl;
	}	
	if(G54.DoesOverlay(&T53))
	{
		cerr << "G54 overlays T53" << endl;
	}
	cerr << endl << endl << endl;

	//Testing print thorugh pointers to shapes

	return 0;
}
