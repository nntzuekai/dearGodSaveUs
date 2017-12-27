TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    Colour.cpp \
    DisplayBackground.cpp \
    EasyBMP.cpp \
    Gasket.cpp \
    Rectangle.cpp \
    Shape.cpp \
    Triangle.cpp \
    ShapeException.cpp \
    Frame.cpp \
    rectangleTestNew.cpp

HEADERS += \
    Colour.h \
    DisplayBackground.h \
    EasyBMP.h \
    EasyBMP_BMP.h \
    EasyBMP_DataStructures.h \
    EasyBMP_VariousBMPutilities.h \
    Gasket.h \
    Rectangle.h \
    Shape.h \
    Triangle.h \
    Frame.h \
    ShapeException.h
