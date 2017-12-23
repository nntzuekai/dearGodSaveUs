objects = Colour.o DisplayBackground.o EasyBMP.o Gasket.o test.o Triangle.o Shape.o Rectangle.o
test.exe : $(objects)
	g++ $(objects) -o test -std=c++11 
Colour.o : Colour.cpp Colour.h EasyBMP.h EasyBMP_BMP.h EasyBMP_DataStructures.h EasyBMP_VariousBMPutilities.h
	g++ -c Colour.cpp -std=c++11
DisplayBackground.o : Colour.h DisplayBackground.cpp DisplayBackground.h EasyBMP.h EasyBMP_BMP.h EasyBMP_DataStructures.h EasyBMP_VariousBMPutilities.h
	g++ -c DisplayBackground.cpp -std=c++11
EasyBMP.o : EasyBMP.cpp EasyBMP.h EasyBMP_BMP.h EasyBMP_DataStructures.h EasyBMP_VariousBMPutilities.h
	g++ -c EasyBMP.cpp -std=c++11
Shape.o : Shape.cpp Shape.h Colour.h
	g++ -c Shape.cpp -std=c++11
Triangle.o : Triangle.cpp Triangle.h Colour.h 
	g++ -c Triangle.cpp -std=c++11
Rectangle.o : Rectangle.cpp Rectangle.h Colour.h Shape.h
	g++ -c Rectangle.cpp -std=c++11
Gasket.o : Gasket.cpp Gasket.h Colour.h Triangle.h
	g++ -c Gasket.cpp -std=c++11
test.o : test.cpp Shape.h
	g++ -c test.cpp -std=c++11

clean:
	rm test $(objects)