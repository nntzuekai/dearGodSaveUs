#include <iostream>
#include "AddressBook.h"

using namespace std;

int main()
{
	AddressBook book1,book2;
	BusinessContact B1("Janice","Regan");
	BusinessContact B2(B1);
	//B1.Print();

	Friend F1("Janice","Regan");
	//F1.Print();

	book1.InsertContact(B1,book1.FindNextContact(B1));
	book2.InsertContact(B2,book2.FindNextContact(B2));

	cout<<(book1==book2)<<endl;


	return 0;
}
