/*
    contactTest.cpp----test program for testing implemented Contact classes
    Author: Xuanda Yang, Ge Shi
    Student ID: 3160105364(Yang) 3160103825(Shi)
    Date: 2017-11-08
*/
#include "BusinessContact.h"
#include "Contact.h"
#include "FamilyMember.h"
#include "Friend.h"
#include <algorithm>
#include <array>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    const string tooLongName = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstu"
                               "vwxyzabcdefghijklmnopqrstuvwxyz"; // 78
    const string tooLongAddress =
        "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqr"
        "stuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz"; // 130

    const string tooLongDigits = "01234567890123456789";

    cout << "Testing program" << endl;

    std::array<Contact *, 20> arr;

    arr[0] = new Contact("Janice", "Regan", "123 A street", "1322223333",
                         "jregan2@gmail.com");
    arr[1] = new Contact("Janic*e", "Reg!an", "12?3 A street", "132)2223333",
                         "jregan2@gmai^l.com");
    arr[2] = new Contact(tooLongName, tooLongName, tooLongAddress, tooLongDigits,
                         "abcdefghijklmnopqrstuvwxyz@"
                         "abcdefghijklmnopqrstuvwxyz."
                         "abcdefghijklmnopqrstuvwxyz");
    arr[3] = new BusinessContact("anny", "jones", "Suite 3 abc building",
                                 "222 5555 7777", "anyjon@suiteco.com", "SuiteCo",
                                 "sales rep", "9:30-3:00");
    arr[4] = new BusinessContact("Janice", "Regan", "123 A street", "1322223333",
                                 "jregan2@gmail.com", "comp!!any", "po@sition",
                                 "123!!345");
    arr[5] = new BusinessContact("Janice", "Regan", "123 A street", "1322223333",
                                 "jregan2@gmail.com", tooLongAddress,
                                 tooLongAddress, tooLongAddress);
    arr[6] =
        new Friend("joe", "hu", "444 5th avenue", "333-444-5555", "jhu44@ss.com",
                   "18/08/2002", "444 2344 5678", "SPELUNKY");
    arr[7] =
        new Friend("joe", "hu", "444 5th avenue", "333-444-5555", "jhu44@ss.com",
                   "1!!8/0a8/2002", "44xx4 23??44 5678", "SPE*LUNKY");
    arr[8] =
        new Friend("joe", "hu", "444 5th avenue", "333-444-5555", "jhu44@ss.com",
                   "18/08/200218/08/200218/08/2002", tooLongDigits, tooLongName);
    arr[9] = new FamilyMember("suzy", "wu", "99 fern road", "222 5432 7766",
                              "123swu@abc.edu", "25/03/1990", "sister in law");
    arr[10] =
        new FamilyMember("suzy", "wu", "99 fern road", "222 5432 7766",
                         "123swu@abc.edu", "2!!5/0!!3/1990", "sister? in? law?");
    arr[11] = new FamilyMember("suzy", "wu", "99 fern road", "222 5432 7766",
                               "123swu@abc.edu", "18/08/200218/08/200218/08/2002",
                               tooLongName);

    std::for_each(arr.begin(), arr.begin() + 12, [](const Contact *contact) {
        contact->Print();
        cout << endl;
    });

    return 0;
}

/*
int constructorTest() {
    Contact C1;
    C1.Print();
    cout << endl;

    Contact C2("Janice", "Regan", "123 A street", "1322223333",
               "jregan2@gmail.com");
    C2.Print();
    cout << endl;

    Friend F1;
    F1.Print();
    cout << endl;

    Friend F2("joe", "hu", "444 5th avenue", "333-444-5555", "jhu44@ss.com",
              "18/08/2002", "444 2344 5678", "SPELUNKY");
    F2.Print();
    cout << endl;

    BusinessContact B1;
    B1.Print();
    cout << endl;

    BusinessContact B2("anny", "jones", "Suite 3 abc building", "222 5555 7777",
                       "anyjon@suiteco.com", "SuiteCo", "sales rep",
                       "9:30-3:00"); // FIXME: wrong workingHour ':', '-'
    B2.Print();
    cout << endl;

    FamilyMember M1;
    M1.Print();
    cout << endl;

    FamilyMember M2("suzy", "wu", "99 fern road", "222 5432 7766",
                    "123swu@abc.edu", "25/03/1990", "sister in law");
    M2.Print();
    cout << endl;

    return 0;
}
*/