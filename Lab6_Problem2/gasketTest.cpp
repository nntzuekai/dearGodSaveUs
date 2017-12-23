#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <string>
#include "EasyBMP.h"
#include "Colour.h"
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
	char numbers[10] = {'\0'};
    char myFileName[128] = {'\0'};


    Rectangle R1; 
    Rectangle R2( 220, 440, C2);
    Rectangle R3( 350, 355, 225, 250, C3 );
    Rectangle R4( 40, 300, 410, 450, C4);
    Rectangle R5( 100, 410, 330, 290, C5);
    Rectangle R6(R4);
	Rectangle R7( 200, 190, 200, 150, C7 );
	Rectangle R8( 50, 100, 280, 160, C8);

    cout << "TESTING THREE CONSTRUCTORS: Printing R1 (default), R2(3 arg) and R3( 4 arg)" << endl;
    R1.RectanglePrint();
    cout << endl;
    R2.RectanglePrint();
    cout << endl;
    R3.RectanglePrint();
    cout << endl << endl << endl;

    
    cout << "TESTING COPY CONSTRUCTOR" << endl;
    cout << "R4, rectangle to copy" << endl;
    R4.RectanglePrint();
    cout << endl << "R6, created with copy constructor " << endl;
    R6.RectanglePrint();
	cout << endl << "testing self copy" << endl;
	R6 = Rectangle(R6);
	
    cout << endl << endl << endl;


    cout << "TESTING GETTERS" << endl;
    cout << "getting values from R6" << endl;
    R6.RectanglePrint();
    cout << endl;
    cout << "Getting Width " << R6.GetWidth() << endl;
    cout << "Getting Height " << R6.GetHeight() << endl;
    cout << "Getting xLocation " << R6.GetXLocation() << endl; 
    cout << "Getting yLocation " << R6.GetYLocation() << endl;
    cout << "Getting rectanglesCreated " << R6.GetRectanglesCreated()<< endl;
    cout << "Getting rectanglesExisting " << R6.GetRectanglesExisting() << endl;
    cout << "Getting blockColour " << R6.GetBlockColour() << endl;
    cout << endl << endl << endl;


    cout << "TESTING SETTERS: changing default values in R1 and R2" << endl;
    cout << "None of the following 7 changes result in a Rectangle that"  
	     << endl << " is partially or completely off the page" << endl;
	cout << endl << "R1 before changes" << endl;     
    R1.RectanglePrint();
    cout << endl;
    R1.SetWidth(220);
    cout << "set R1.width set to 220" << endl;
    R1.SetHeight(100);
    cout << "set R1.height set to 100" << endl;
    R1.SetXLocation(100);
    cout << "set R1.xLocation set to 100" << endl;
    R1.SetYLocation(225);
    cout << "set R1.yLocation set to 225" << endl;
    R1.SetColour(C6);
    cout << "set R1.Colour set to " << C6 << endl << endl;
    cout << "modified R1" << endl;
    R1.RectanglePrint();
    cout << endl << endl;
    
    cout << "R2 before changes" << endl;
    R2.RectanglePrint();
    cout << endl;
    cout << "set R2.height to 280" << endl;
    cout << "set R2.width to 100" << endl;
	R2.SetHeight(225);
    R2.SetWidth(100);
    cout << "modified R2" << endl;
    R2.RectanglePrint();
    cout << endl << endl << endl;


    cout << "TESTING OVERLAY" << endl;
    if(R1.DoesOverlay(R2))
    {
        cout << "R1 overlays R2" << endl;
    }
    if(R1.DoesOverlay(R3))
    {
        cout << "R1 overlays R3" << endl;
    }
    if(R1.DoesOverlay(R4))
    {
        cout << "R1 overlays R4" << endl;
    }
    if(R1.DoesOverlay(R5))
    {
        cout << "R1 overlays R5" << endl;
    }
	if(R1.DoesOverlay(R7))
    {
        cout << "R1 overlays R7" << endl;
    }
	if(R1.DoesOverlay(R8))
    {
        cout << "R1 overlays R8" << endl;
    }
    if(R2.DoesOverlay(R1))
    {
        cout << "R2 overlays R1" << endl;
    }
    if(R2.DoesOverlay(R3))
    {
        cout << "R2 overlays R3" << endl;
    }
    if(R2.DoesOverlay(R4))
    {
        cout << "R2 overlays R4" << endl;
    }
    if(R2.DoesOverlay(R5))
    {
        cout << "R2 overlays R5" << endl;
    }
	if(R2.DoesOverlay(R7))
    {
        cout << "R2 overlays R7" << endl;
    }
	if(R2.DoesOverlay(R8))
    {
        cout << "R2 overlays R8" << endl;
    }
	if(R3.DoesOverlay(R1))
    {
        cout << "R3 overlays R1" << endl;
    }
    if(R3.DoesOverlay(R2))
    {
        cout << "R3 overlays R2" << endl;
    }
    if(R3.DoesOverlay(R4))
    {
        cout << "R3 overlays R4" << endl;
    }
    if(R3.DoesOverlay(R5))
    {
        cout << "R3 overlays R5" << endl;
    }
	if(R3.DoesOverlay(R7))
    {
        cout << "R3 overlays R7" << endl;
    }
    if(R3.DoesOverlay(R8))
    {
        cout << "R3 overlays R8" << endl;
    }
    if(R4.DoesOverlay(R1))
    {
        cout << "R4 overlays R1" << endl;
    }
    if(R4.DoesOverlay(R2))
    {
        cout << "R4 overlays R2" << endl;
    }
    if(R4.DoesOverlay(R3))
    {
        cout << "R4 overlays R3" << endl;
    }	
    if(R4.DoesOverlay(R5))
    {
        cout << "R4 overlays R5" << endl;
    }
	if(R4.DoesOverlay(R7))
    {
        cout << "R4 overlays R7" << endl;
    }
	if(R4.DoesOverlay(R8))
    {
        cout << "R4 overlays R8" << endl;
    }
    if(R5.DoesOverlay(R1))
    {
        cout << "R5 overlays R1" << endl;
    }
    if(R5.DoesOverlay(R2))
    {
        cout << "R5 overlays R2" << endl;
    }
    if(R5.DoesOverlay(R3))
    {
        cout << "R5 overlays R3" << endl;
    }	
    if(R5.DoesOverlay(R4))
    {
        cout << "R5 overlays R4" << endl;
    }	
	if(R5.DoesOverlay(R7))
    {
        cout << "R5 overlays R7" << endl;
    }	
	if(R5.DoesOverlay(R8))
    {
        cout << "R5 overlays R8" << endl;
    }
	if(R7.DoesOverlay(R1))
    {
        cout << "R7 overlays R1" << endl;
    }
    if(R7.DoesOverlay(R2))
    {
        cout << "R7 overlays R2" << endl;
    }
    if(R7.DoesOverlay(R3))
    {
        cout << "R7 overlays R3" << endl;
    }	
    if(R7.DoesOverlay(R4))
    {
        cout << "R7 overlays R4" << endl;
    }	
	if(R7.DoesOverlay(R5))
    {
        cout << "R7 overlays R5" << endl;
    }	
	if(R7.DoesOverlay(R8))
    {
        cout << "R7 overlays R8" << endl;
    }	
	if(R8.DoesOverlay(R1))
    {
        cout << "R8 overlays R1" << endl;
    }
    if(R8.DoesOverlay(R2))
    {
        cout << "R8 overlays R2" << endl;
    }
    if(R8.DoesOverlay(R3))
    {
        cout << "R8 overlays R3" << endl;
    }	
    if(R8.DoesOverlay(R4))
    {
        cout << "R8 overlays R4" << endl;
    }	
	if(R8.DoesOverlay(R5))
    {
        cout << "R8 overlays R5" << endl;
    }	
	if(R8.DoesOverlay(R7))
    {
        cout << "R8 overlays R7" << endl;
    }	
    cout << endl << endl << endl;


    cout << "TESTING INTERSECT" << endl;
    if(R1.DoesIntersect(R2))
    {
        cout << "R1 intersects R2" << endl;
    }
    if(R1.DoesIntersect(R3))
    {
        cout << "R1 intersects R3" << endl;
    }
    if(R1.DoesIntersect(R4))
    {
        cout << "R1 intersects R4" << endl;
    }
    if(R1.DoesIntersect(R5))
    {
        cout << "R1 intersects R5" << endl;
    }
	if(R1.DoesIntersect(R7))
    {
        cout << "R1 intersects R7" << endl;
    }
    if(R1.DoesIntersect(R8))
    {
        cout << "R1 intersects R8" << endl;
    }
    if(R2.DoesIntersect(R1))
    {
        cout << "R2 intersects R1" << endl;
    }
    if(R2.DoesIntersect(R3))
    {
        cout << "R2 intersects R3" << endl;
    }
    if(R2.DoesIntersect(R4))
    {
        cout << "R2 intersects R4" << endl;
    }
    if(R2.DoesIntersect(R5))
    {
        cout << "R2 intersects R5" << endl;
    }
	if(R2.DoesIntersect(R7))
    {
        cout << "R2 intersects R7" << endl;
    }
    if(R2.DoesIntersect(R8))
    {
        cout << "R2 intersects R8" << endl;
    }
    if(R3.DoesIntersect(R1))
    {
        cout << "R3 intersects R1" << endl;
    }
    if(R3.DoesIntersect(R2))
    {
        cout << "R3 intersects R2" << endl;
    }
    if(R3.DoesIntersect(R4))
    {
        cout << "R3 intersects R4" << endl;
    }
    if(R3.DoesIntersect(R5))
    {
        cout << "R3 intersects R5" << endl;
    }
	if(R3.DoesIntersect(R7))
    {
        cout << "R3 intersects R7" << endl;
    }
    if(R3.DoesIntersect(R8))
    {
        cout << "R3 intersects R8" << endl;
    }
    if(R4.DoesIntersect(R1))
    {
        cout << "R4 intersects R1" << endl;
    }
    if(R4.DoesIntersect(R2))
    {
        cout << "R4 intersects R2" << endl;
    }
    if(R4.DoesIntersect(R3))
    {
        cout << "R4 intersects R3" << endl;
    }
    if(R4.DoesIntersect(R5))
    {
        cout << "R4 intersects R5" << endl;
    }
	if(R4.DoesIntersect(R7))
    {
        cout << "R4 intersects R7" << endl;
    }
    if(R4.DoesIntersect(R8))
    {
        cout << "R4 intersects R8" << endl;
    }
    if(R5.DoesIntersect(R1))
    {
        cout << "R5 intersects R1" << endl;
    }
    if(R5.DoesIntersect(R2))
    {
        cout << "R5 intersects R2" << endl;
    }
    if(R5.DoesIntersect(R3))
    {
        cout << "R5 intersects R3" << endl;
    }
    if(R5.DoesIntersect(R4))
    {
        cout << "R5 intersects R4" << endl;
    }
	if(R5.DoesIntersect(R7))
    {
        cout << "R5 intersects R7" << endl;
    }
    if(R5.DoesIntersect(R8))
    {
        cout << "R5 intersects R8" << endl;
    }
	if(R7.DoesIntersect(R1))
    {
        cout << "R7 intersects R1" << endl;
    }
    if(R7.DoesIntersect(R2))
    {
        cout << "R7 intersects R2" << endl;
    }
    if(R7.DoesIntersect(R3))
    {
        cout << "R7 intersects R3" << endl;
    }
    if(R7.DoesIntersect(R4))
    {
        cout << "R7 intersects R4" << endl;
    }
	if(R7.DoesIntersect(R5))
    {
        cout << "R7 intersects R5" << endl;
    }
    if(R7.DoesIntersect(R8))
    {
        cout << "R7 intersects R8" << endl;
    }
	if(R8.DoesIntersect(R1))
    {
        cout << "R8 intersects R1" << endl;
    }
    if(R8.DoesIntersect(R2))
    {
        cout << "R8 intersects R2" << endl;
    }
    if(R8.DoesIntersect(R3))
    {
        cout << "R8 intersects R3" << endl;
    }
    if(R8.DoesIntersect(R4))
    {
        cout << "R8 intersects R4" << endl;
    }
	if(R8.DoesIntersect(R5))
    {
        cout << "R8 intersects R5" << endl;
    }
    if(R8.DoesIntersect(R7))
    {
        cout << "R8 intersects R7" << endl;
    }
    cout << endl << endl << endl;


    cout << "TESTING DISPLAY OF RECTANGLES" << endl;
    //Create the bitmap
    //Load the background bitmap
    //Plot each rectangle to the bitmap
    //Note the last rectangle plotted will appear on
    //to of previous rectangles
    InitBackground(myImage, CB, 600, 800);
    R4.RectangleDisplay(myImage, "rectangleTest.bmp");
    R3.RectangleDisplay(myImage, "rectangleTest.bmp");
	R8.RectangleDisplay(myImage, "rectangleTest.bmp");
    R5.RectangleDisplay(myImage, "rectangleTest.bmp");
    R2.RectangleDisplay(myImage, "rectangleTest.bmp");
	R7.RectangleDisplay(myImage, "rectangleTest.bmp");
    R1.RectangleDisplay(myImage, "rectangleTest.bmp");
	
    cout << endl << endl << endl;

    cout << "TESTING = OPERATOR"<< endl;
    cout << "printing R5"<< endl;
    R5.RectanglePrint();
    cout << "printing R1" << endl;
    R1.RectanglePrint();
	R1 = R1;
    cout << endl;
    cout << "printing R1 after R1=R1"<< endl;
    R1.RectanglePrint();
    cout << endl;
    R1 = R5;
    cout << endl;
    cout << "printing R1 after R1=R5"<< endl;
    R1.RectanglePrint();
    cout << endl << endl << endl;

    cout << "TESTING THE << OPERATOR" << endl;
    cout << "R5" << endl << R5;
    cout << endl << endl << endl;

    //Test the == operator
    cout << "Testing == answer should be true (1) " << (R3==R4);
    cout << endl;
    cout << "Testing == answer should be false (0) " << (R3==R1);
    cout << endl << endl << endl;

    cout << "TESTING RECTANGLES OVERLAPPING EDGES OF PAGE" << endl;
    ResetBackground(myImage, CB, 600, 800);
    
    cout << "RECTANGLE BOTH xLocation AND yLocation OFF THE PAGE";
    cout << ": plotted Red" << endl;
    Rectangle R10( -5, 990, 300, 250, C3 );
    cout << endl;
    R10.RectangleDisplay(myImage, "rectangleTestOut.bmp");
    R10.RectanglePrint();	
		
    cout << endl << "RECTANGLE, yLocation OFF THE PAGE";
    cout << ": plotted Black" << endl;	
    Rectangle R11( 100, 977, 200, 200, C2);
    cout << endl;
    R11.RectangleDisplay(myImage, "rectangleTestOut.bmp");
    R11.RectanglePrint();
    
    cout << endl << "RECTANGLE, xLocation OFF THE PAGE";
    cout << ": plotted dark Blue" << endl;	
    Rectangle R12( 800, 100, 140, 150, C1); 
    cout << endl;
    R12.RectangleDisplay(myImage, "rectangleTestOut.bmp");
    R12.RectanglePrint();
    
    cout << endl << "RECTANGLE, xLocation ON PAGE, xLocation+width OFF THE PAGE";
    cout << ": plotted Pink" << endl;
    Rectangle R13( 450, 150, 300,200, C6);
    cout << endl;
    R13.RectangleDisplay(myImage, "rectangleTestOut.bmp");
    R13.RectanglePrint();
	cout << endl << "move x off page, change colour" << endl;
	R13.SetXLocation(500);

    
    cout << endl << "RECTANGLE, yLocation ON PAGE, yLocation+height OFF THE PAGE";
    cout << ": plotted Light Blue" << endl;
    Rectangle R14( 277, 688, 175, 220, C8);
    cout << endl;
    R14.RectangleDisplay(myImage, "rectangleTestOut.bmp");
    R14.RectanglePrint();
    
    cout << endl << "RECTANGLE, xLocation ON PAGE, xLocation+width OFF THE PAGE";
    cout << endl << "RECTANGLE, yLocation ON PAGE, yLocation+height OFF THE PAGE";
    cout << ": plotted Grey" << endl;
    Rectangle R15( 522, 553, 128, 300, C4);
    cout << endl;
    R15.RectangleDisplay(myImage, "rectangleTestOut.bmp");
    R15.RectanglePrint();
	
	cout << endl << "mutator for x value moves partially off page";
	cout << endl << "mutator for y value moves partially off page";
	cout  << endl << "x moved to 580,  y moved to 700";
    cout << ": plotted Yellow" << endl;
	Rectangle R19( 500, 450, 80, 340, C4);
	R19.SetColour(C7);
	R19.SetXLocation(580);
	R19.SetYLocation(700);
    R19.RectangleDisplay(myImage, "rectangleTestOut.bmp");
    R19.RectanglePrint();
	    cout << endl;
    R19.RectangleDisplay(myImage, "rectangleTestOut.bmp");
	R19.RectanglePrint();

	cout << endl << "mutator for x value moves partially off page";
	cout  << endl << "x moved to 480";
    cout << ": plotted Dark Blue" << endl;
	Rectangle R16( 50, 0, 140, 150, C1);
	R16.SetXLocation(580);
    R16.RectangleDisplay(myImage, "rectangleTestOut.bmp");
    R16.RectanglePrint();

	cout << endl << "mutator for y value moves partially off page";
	cout  << endl << "y moved to 670";
    cout << ": plotted Black" << endl;
	Rectangle R17( 0, 0, 100, 200, C2);
	R17.SetYLocation(670);
    R17.RectangleDisplay(myImage, "rectangleTestOut.bmp");
    R17.RectanglePrint();

	cout << endl << "mutator for width value moves partially off page";
	cout  << endl << "width moved to 370";
    cout << ": plotted Purple" << endl;
	Rectangle R18( 440, 400, 100, 120, C8);
	R18.SetWidth(370);
    R18.RectangleDisplay(myImage, "rectangleTestOut.bmp");
    R18.RectanglePrint();

	cout << endl << "mutator for height value moves partially off page";
	cout  << endl << "height moved to 370";
    cout << ": plotted Red" << endl;
	Rectangle R20( 110, 600, 100, 120, C7);
	R20.SetHeight(250);
    R20.RectangleDisplay(myImage, "rectangleTestOut.bmp");
    R20.RectanglePrint();

    cout << endl << endl << endl;
    cout << "????????????????????????????????????????????????????";


    cout << "BEGIN TRIANGLE TEST" << endl << endl;
    Triangle T1;
    Triangle T2( 280, 524, 200, C2);
    Triangle T3( 250, 300, 325,  C3 );
    Triangle T4( 44, 70, 450,  C4);
    Triangle T5( 400, 590, 180,  C5);
    Triangle T6(T2);

    cout << "TESTING THREE CONSTRUCTORS: Printing T1(default), T2(3arg) and T3(4arg)" << endl;
    cout << "ALSO TESTING PRINT FUNCTION" << endl;
    ResetBackground(myImage, CB, 600, 800);
    T1.TrianglePrint();
    cout << endl;
    T2.TrianglePrint();
    cout << endl;
    T3.TrianglePrint();
    cout << endl << endl << endl;


    cout << "TESTING COPY CONSTRUCTOR" << endl;	
    cout << "Triangle to copy" << endl;
    T2.TrianglePrint();
    cout << "Triangle created with copy constructor" << endl;
    T6.TrianglePrint();
    cout << endl << endl << endl;


    cout << "TESTING GETTERS" << endl;    
	cout << "getting values from T6" << endl;
    T6.TrianglePrint();
    cout << endl;
    cout << "Getting Width " << T6.GetSideLength() << endl;
    cout << "Getting xLocation " << T6.GetXLocation() << endl; 
    cout << "Getting yLocation " << T6.GetYLocation() << endl;
    cout << "Getting trianglesCreated " << T6.GetTrianglesCreated()<< endl;
    cout << "Getting trianglesExisting " << T6.GetTrianglesExisting() << endl;
    cout << "Getting blockColour " << T6.GetTriangColour() << endl;
    cout << endl << endl << endl;


    cout << "TESTING SETTERS: changing default values in T1 and T2" << endl;
        cout << "None of the following 6 changes result in a Triangle that"  
	     << endl << " is partially or completely off the page" << endl;
	cout << endl << "T1 before changes" << endl; 
	T1.TrianglePrint();
	cout << endl;
	cout << "setting R1.sideLength to 330" << endl;
    T1.SetSideLength(330);
    cout << "setting R1.xLocation to 25"  << endl;
    T1.SetXLocation(25);
    cout << "setting R1.yLocation to 480"  << endl;
    T1.SetYLocation(480);
    cout << "setting R1.TriangleColour to C7" << endl;
    T1.SetTriangColour(C7);
    cout << "modified R1" << endl;
    T1.TrianglePrint();
    cout << endl;
    cout << "T2 before changes" << endl;
    T2.TrianglePrint();
    cout << endl << "setting sideLength to 50" << endl;
    T2.SetSideLength(210);
	cout << "modified R2" << endl;
    T2.TrianglePrint();
    cout << endl << endl << endl;


    cout << "TESTING DISPLAY OF TRIANGLES" << endl;
    T4.TriangleDisplay(myImage, "triangleTest.bmp");
    T3.TriangleDisplay(myImage, "triangleTest.bmp");
    T5.TriangleDisplay(myImage, "triangleTest.bmp");
    T1.TriangleDisplay(myImage, "triangleTest.bmp");
    T2.TriangleDisplay(myImage, "triangleTest.bmp");
    cout << endl << endl << endl;


    cout << "TESTING = OPERATOR"<< endl;
    cout << "printing T3"<< endl;
    T3.TrianglePrint();
    cout << "printing T4" << endl;
	T4.TrianglePrint();
	cout << endl;
    cout << "printing T4 after T4=T3"<< endl;
    T4 = T3;
    T4.TrianglePrint();
    cout << endl << endl << endl;

    cout << "TESTING THE << OPERATOR" << endl;
    cout << "T5" << endl << T5;
    cout << endl << endl << endl;

    //Test the == operator
    cout << "Testing == answer should be true (1) " << (R3==R4);
    cout << endl;
    cout << "Testing == answer should be false (0) " << (R3==R1);
    cout << endl << endl << endl;

    cout << endl;
    cout << "TESTING TRIANGLES OVERLAPPING EDGES OF PAGE" << endl;
    cout << "AND TESTING TRIANGLES OUTSIDE THE PAGE" << endl;
    ResetBackground(myImage, CB, 600, 800);
    cout << "TRIANGLE BOTH xLocation AND yLocation OFF THE PAGE";
    cout << ": plotted Red" << endl;
    Triangle T10( -20, -100, 400, C3 );
    cout << endl;
    T10.TriangleDisplay(myImage, "triangleTestOut.bmp");
    T10.TrianglePrint();
    cout << endl << "TRIANGLE, yLocation OFF THE PAGE";
    cout << ": plotted Black" << endl;
    Triangle T11( 140, 900, 300, C2);
    cout << endl;
    T11.TriangleDisplay(myImage, "triangleTestOut.bmp");
    T11.TrianglePrint();
    cout << endl << "TRIANGLE, xLocation OFF THE PAGE";
    cout << ": plotted Grey" << endl;
    Triangle T12( 700, 400, 200, C4); 
    cout << endl;
    T12.TriangleDisplay(myImage, "triangleTestOut.bmp");	
    T12.TrianglePrint();
    cout << endl << "TRIANGLE, xLocation ON PAGE, xLocation+width OFF THE PAGE";
    cout << ": plotted Dark Blue" << endl;
    Triangle T13( 400, 50, 250, C1);
    cout << endl;
    T13.TriangleDisplay(myImage, "triangleTestOut.bmp");
    T13.TrianglePrint();
    cout << endl << "TRIANGLE, yLocation ON PAGE, yLocation+height OFF THE PAGE";
    cout << ": plotted Grey" << endl;
    Triangle T14( 180, 550, 410, C4);
    cout << endl;
    T14.TriangleDisplay(myImage, "triangleTestOut.bmp");
    T14.TrianglePrint();
    cout << endl << "TRIANGLE, xLocation ON PAGE, xLocation+sideLength OFF THE PAGE";
    cout << endl << "TRIANGLE, yLocation ON PAGE, yLocation+height OFF THE PAGE";
    cout << endl << "TRIANGLE, yLocation+height off page after scaling for x";
    cout << ": plotted Pink" << endl;
    Triangle T15( 350, 600, 330, C6);
    cout << endl;
    T15.TrianglePrint();
    T15.TriangleDisplay(myImage, "triangleTestOut.bmp");
    cout << endl << "TRIANGLE, xLocation ON PAGE, xLocation+sideLength OFF THE PAGE";
    cout << endl << "TRIANGLE, yLocation ON PAGE, yLocation+height OFF THE PAGE";
    cout << endl << "TRIANGLE, yLocation+height on page after scaling for x";
    cout << ": plotted Light Blue" << endl;
    Triangle T16( 300,300,400, C5);
    cout << endl;
    T16.TriangleDisplay(myImage, "triangleTestOut.bmp");
    T16.TrianglePrint();
    
    // TEST MUTATORS Moving off the page
    cout << "Mutators moving the shape completely or partially off the page" << endl
    << endl;
    cout << endl << "TRIANGLE: move triangle so xLocation=650, off page";
    cout << endl << ": plotted yellow at 0,0" << endl;
	Triangle T17( 420, 400, 120, C7);
    T17.SetXLocation(650);
    T17.TriangleDisplay(myImage, "triangleTestOut.bmp");
    T17.TrianglePrint();
    
	cout << endl << "move triangle so triangle in y so it is partially off the page \n"
	     << endl << " change ylocation to 530 " << endl;
    cout << endl << ": plotted Purple" << endl;
	Triangle T18( 50, 350, 330, C8);
    T18.SetYLocation(530);	
    T18.TrianglePrint();
    T18.TriangleDisplay(myImage, "triangleTestOut.bmp");
    cout << endl << endl << endl;
	
	cout << endl << "change sidelength so triangle is off the page in y\n"
	     << endl << " change sideLength to 165" << endl << "TRIANGLE: move T15, change sideLength so off page in y";
    cout << endl << ": plotted Black" << endl;
	Triangle T20( 50, 675, 100, C2);
    T20.SetSideLength(165);	cout << endl;
    T20.TrianglePrint();
    T20.TriangleDisplay(myImage, "triangleTestOut.bmp");
    cout << endl << endl << endl;

	cout << endl << "move triangle so triangle in x so it is partially off the page"
	     << endl << " change xlocation to 510 " ;
    cout <<  ": plotted Red" << endl;
	Triangle T21( 450, 230, 130, C3);
    T21.SetXLocation(510);	
    T21.TrianglePrint();
    T21.TriangleDisplay(myImage, "triangleTestOut.bmp");
    cout << endl << endl << endl;
	
	cout << endl << "change sidelength so triangle is off the page in x"
	     << endl << " change sideLength to 165";
    cout << ": plotted Purple" << endl;
	Triangle T22( 470, 475, 100, C8);
    T22.SetSideLength(165);	
    T22.TrianglePrint();
    T22.TriangleDisplay(myImage, "triangleTestOut.bmp");

	cout << endl << "change sidelength so triangle is off the page in x and y"
	     << endl << " change sideLength to 165";
    cout << ": plotted Yellow" << endl;
	Triangle T23( 470, 695, 100, C7);
    T23.SetSideLength(165);	
    T23.TrianglePrint();
    T23.TriangleDisplay(myImage, "triangleTestOut.bmp");
    cout << endl << endl << endl;

    cout << "TESTING TRIANGLE DIVIDE" << endl;
    Triangle *TList = NULL;
    TList = new Triangle[3];
    // plot the undivided triangle in blue
    Triangle T19( 330,150,140, C1);
    T19.TriangleDisplay(myImage, "triangleTestOut.bmp");
    cout << "the triangle that will be divided" << endl;
    T19.TrianglePrint();
    // plot the subtriangles in yellow
    T19.SetTriangColour(C7);
    T19.TriangleDivide ( TList );
    cout << "the list of three subtriangles: Plotted Yellow" << endl;
    for( int i=0; i<3; i++)
    {
        TList[i].TriangleDisplay(myImage, "triangleTestOut.bmp");
        TList[i].TrianglePrint();
        cout << endl;
    }
    delete [] TList;
    cout << endl << endl << endl;

        cout << endl << endl << endl;


    cout << "????????????????????????????????????????????????????";


    cout << "BEGIN GASKET TEST" << endl << endl;

    //Gasket test here




    cout << "TESTING CONSTRUCTORS: ON AND OFF PAGE" << endl;
    ResetBackground(myImage, CB, 600, 800);
    cout << endl << "Constructor 4 arguments, xLocation off page:: RED" << endl;
	cout << "create g6" << endl;
    Gasket G6(2, 606, 300, 480, C3);
    G6.GasketDisplay(myImage, 0, "GasketConstructors.bmp");
    G6.GasketPrint();
    cout << endl << "Constructor 4 arguments, yLocation off page:: LIGHT BLUE" << endl;
	cout << "create g7" << endl;
    Gasket G7(0, 300, 811, 321, C5);
    G7.GasketDisplay(myImage, 0, "GasketConstructors.bmp");
    G7.GasketPrint();
    cout << endl << "Contructor with 4 arguments x and y off page: YELLOW" << endl;
	cout << "create G1" << endl;
    Gasket G0(1, -1, -1, 270, C7);
	G0.GasketDisplay(myImage, 0, "GasketConstructors.bmp");
	G0.GasketPrint();
	cout << "create G0" << endl;
	cout << endl << "Default constructor: BLACK" << endl;
	Gasket G1;
    G1.GasketDisplay(myImage, 0, "GasketConstructors.bmp");
    G1.GasketPrint();
    cout << endl << "Constructor with 4 arguments on page: PURPLE" << endl;	
	cout << "create G2" << endl;
    Gasket G2(0, 50, 480, 340, C8);
    G2.GasketDisplay(myImage, 0, "GasketConstructors.bmp");
    G2.GasketPrint();
    cout << endl << "Constructor 4 arguments, sidelength (x) beyond edge of page: GREY" << endl;
	cout << "create G3" << endl;
    Gasket G3(1, 350, 330, 280, C4);
    G3.GasketDisplay(myImage, 1, "GasketConstructors.bmp");
    G3.GasketPrint();
    cout << endl << "Constructor 4 arguments, sideLength (y) beyond edge of page: DARK BLUE" << endl;
	cout << "create g5" << endl;
    Gasket G5(1, 40, 700, 200, C1);
    G5.GasketDisplay(myImage, 1, "GasketConstructors.bmp");
    G5.GasketPrint();
	cout << endl << "Constructor 4 argument x and y beyond edge of page: X correction only: YELLOW" << endl;   
	cout << "create G8" << endl;
	Gasket G8( 1, 400, 600, 300, C7);
	G8.GasketDisplay(myImage, 0, "GasketConstructors.bmp" );
	G8.GasketPrint();
	cout << endl << endl << endl;
	cout << endl << "Constructor 4 argument x and y beyond edge of page: X correction only: GREY" << endl;   
	cout << "create G9" << endl;
	Gasket G9( 1, 400, 700, 300, C4);
	G9.GasketDisplay(myImage, 0, "GasketConstructors.bmp" );
	G9.GasketPrint();
	cout << endl << endl << endl;

    cout << "TESTING COPY CONSTRUCTOR" << endl;	
    cout << "gasket to copy" << endl;
    G5.GasketPrint();
    Gasket G10(G5);
    cout << "copied gasket" << endl;
    G10.GasketPrint();
    cout << endl << endl << endl;


    ResetBackground(myImage, CB, 600, 800);
    cout << endl << "changing side length of G0 from 270 to 150: ";
	cout << " :displayed in YELLOW" << endl;
    G0.SetSideLength(150);
    G0.GasketDisplay(myImage, 0, "GasketMutators.bmp");
    G0.GasketPrint();
    cout << endl << "changing xlocation and ylocation of G1"<< endl;
	cout << "xlocation to 150 ylocation to 200: "  << endl;
	cout << "displayed in BLACK" << endl;
    G1.SetXLocation(100);
    G1.SetYLocation(200);
    G1.GasketDisplay(myImage, 0, "GasketMutators.bmp");
    G1.GasketPrint();	
    cout << "moving y location of G7 so gasket is partially off the page" << endl;
    cout << "yLocation set to 675: displayed in LIGHT BLUE" << endl;
    G7.SetYLocation( 675 );
    G7.GasketDisplay(myImage, 0, "GasketMutators.bmp");
    G7.GasketPrint();
	cout << "moving y location of G7 and increasing sideLength" << endl;
    cout << "yLocation set to 575 sideLength to 300: displayed in LIGHT BLUE" << endl;
    G7.SetYLocation( 575 );
	G7.SetSideLength(300);
    G7.GasketDisplay(myImage, 0, "GasketMutators.bmp");
    G7.GasketPrint();
	cout << "TESTING MUTATORS" << endl;
    cout << "changing G2 colour from light blue: ";
    cout << "displayed in RED" << endl;
    G2.SetGasketColour(C3);
    G2.GasketDisplay(myImage, 0, "GasketMutators.bmp");
    G2.GasketPrint();
    cout << "changing G2 number of iterations from 1 to 3: " ;
    cout << "displayed in YELLOW" << endl;
    G2.SetGasketColour(C7);
    G2.SetIterations(3);
    G2.GasketDisplay(myImage, 0, "GasketMutators.bmp");
    G2.GasketPrint();
    cout << "moving xLocation of G6 so gasket is partially off the page" << endl;
    cout << "xLocaton set to 300: displayed in RED" << endl;
    G6.SetXLocation(300);
    G6.GasketDisplay(myImage, 1, "GasketMutators.bmp");
    G6.GasketPrint();
	cout << "moving yLocation of G6 to 250, changing colour: " << endl;
    cout << " displayed in DARK BLUE" << endl;
    G6.SetYLocation(250);
	G6.SetGasketColour(C1);
    G6.GasketDisplay(myImage, 1, "GasketMutators.bmp");
    G6.GasketPrint();
	cout << "moving yLocation of G6 to 375, changing iterations to 0: " << endl;
    cout << " displayed in DARK BLUE" << endl;
    G6.SetYLocation(375);
	G6.SetIterations(0);
    G6.GasketDisplay(myImage, 1, "GasketMutators.bmp");
    G6.GasketPrint();
	cout << "moving yLocation of G6 to 675, xLocation to 475: " << endl;
    cout << " displayed in DARK BLUE" << endl;
    G6.SetYLocation(675);
	G6.SetXLocation(375);
    G6.GasketDisplay(myImage, 1, "GasketMutators.bmp");
    G6.GasketPrint();



    cout << "Producing on page gaskets for 2 to 4 iterations";
    for (int k=2; k <= 5; k++)
    {	
		string myFileName;
    	ostringstream numString;
    	numString << k;
    	
        myFileName="BitFileG";   
        myFileName += numString.str();
        myFileName += ".bmp";
        Gasket G4(k, 50, 200, 500, C2);
        ResetBackground(myImage,C3, 600, 800);
        G4.GasketDisplay(myImage, 0, myFileName);
    }

    return 0;
}


