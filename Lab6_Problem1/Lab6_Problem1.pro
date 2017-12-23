TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    AddressBook.cpp \
    BusinessContact.cpp \
    Contact.cpp \
    FamilyMember.cpp \
    Friend.cpp

HEADERS += \
    AddressBook.h \
    BusinessContact.h \
    Contact.h \
    FamilyMember.h \
    Friend.h
