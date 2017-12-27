#include <iostream>
#include <string>
#include "Contact.h"
#include "Friend.h"
#include "FamilyMember.h"
#include "BusinessContact.h"
#include "AddressBook.h"

using namespace std;

int main()
{
	AddressBook A1;
	unsigned int insertIndex = 0;
	
	//correct 4 argument constructor 
	Contact *C1p = NULL;
	C1p = new Contact( "Janice", "Regan", "add", "1322223333", "jregan2@gmail.com");
	A1.InsertContact(C1p,insertIndex);
	
	//illegal characters all strings 4 argument constructor
	Contact *C2p = NULL;
	C2p = new Contact( "Janiceabcdefgh1,.b", "/R`e*g2a;n",
		"add home !@#$*()_", "1-32.222a33v33", 
				 "jregan2@g/ *mail.com");
	insertIndex = A1.FindNextContact(*C2p); 
	A1.InsertContact(C2p, insertIndex);

	//all strings too long 4 argument constructor
	Contact *C3p = NULL;
	C3p = new Contact( "Janiceaaaajjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjj", 
				"Regan1aaaassssddddffffgggghhhhjjjjkkkkllllppppvvvvbbbbnnnnmmmmccccnnnn", 
				"addaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbacccccccccccccccccccddddddddddddfeeeeeeeeeeeejjjjjjjjjjjkkkkkkkkkkkkkkllllllllllllllllllllllmmmmmmmmmmmmmmmmmmmmmmmlll",
				"13d22223333444444444", 
				"jregan2@gmail.comiiiiiiiiiiijjjjjjjjjjkkkkkkkkkkklllllllllllllllllllmmmmmmmmmmnnnnnnnnnnnn");
	insertIndex = A1.FindNextContact(*C3p); 
	A1.InsertContact(C3p, insertIndex);

	//correct 4 argument constructor BusinessCOntact
	BusinessContact* B1p = NULL;
	B1p = new BusinessContact("anny", "jones", "Suite 3 abc building", "222 5555 7777" , "anyjon@suiteco.com", "SuiteCo", "sales rep", "9:30-3:00" );
	insertIndex = A1.FindNextContact(*B1p); 
	A1.InsertContact(B1p, insertIndex);

	//all strings with incorrect characters
	BusinessContact* B2p = NULL;
	B2p = new BusinessContact("a'*nn,)fy", "xjo..--nes;", "Suite ^^3 abc building", "222pp 5555x 7777" , "anyjon@su///iteco.com/", "Su.,.iteCo", "sales$#@ rep", "9:3a0-3:x00" );
	insertIndex = A1.FindNextContact(*B2p); 
	A1.InsertContact(B2p, insertIndex);

	//all strings too long
	BusinessContact *B3p = NULL;
	B3p = new BusinessContact("annyxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxddddddddddccccccccccgggggggggghhhhhhhhhh", 
		"jonesfaslfas;ajsldfajlhwiejflfkjbvlkjwehrlksjhflsjdhfalkjsdhlfajlakfhkajsdkllasjdflaskjflaksjdfaldjfl", 
		"Suite 3 abc buildinghasdglfahsdglfahsdfkjasdlkflasgkdjflaksjdlgfkasjdfkajsdklfjasdglfkasgdlfkjgsakjdgfajsldfasjdflaksjgdkfasjdlafksdjfgalksjdflaskdjflaskdjflaksfkasjdfl", 
		"111111222 5555 7777" , 
		"anyjon@s@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.................444444444555a55555555555asdfaskkkkkkkk", 
		"Suiteajdlfasd aslfsjdfhla qewrq1122343124 haskdfjahk34r53k4q faf aslfjhi3q4u2514 51               adsjafhsdfjhkashfkjaslCoakjjflaksjaaaaaaaaaa32543058888888888888333453543", 
		"sales alskdfa;sldkf   a44444444444444444445555555555555556666666666666666888888888888888666666666666444444444444           444444444444444kkkkkkkkkffffffffffffffxxxxxxxrep", 
		"9:30-3:00asdfskkkkkkkkkkklslllllllllld          ssssssssssssddddddddddd        rrrrrrrrrrrrlllllllllll44444444444ooooooooooasdddddddddddddd        kkkkkkkkkkaaaaaaaaaaadfa" );
	insertIndex = A1.FindNextContact(*B3p); 
	A1.InsertContact(B3p, insertIndex);

	// Friend all strings ok
	Friend *F1p = NULL;
	F1p = new Friend( "joe", "hu", "444 5th avenue", "333-444-5555",  "jhu44@ss.com", "18/08/2002", "444 2344 5678", "SPELUNKY" );
	insertIndex = A1.FindNextContact(*F1p); 
	A1.InsertContact(F1p, insertIndex);

	// Friend all strings invalid characters
	Friend *F2p = NULL;
	F2p = new Friend( "joey123.,,-23", "hunn;-=12x", "444-5th &#!avenue", "333?444-5555",  "jhu44@{}x()ss.com", "18a/08b/2002", "444x2344q5678", "//SPELUx//NKY" );
	insertIndex = A1.FindNextContact(*F2p); 
	A1.InsertContact(F2p, insertIndex);

	// Friend all strings too long
	Friend *F3p = NULL;
	F3p = new Friend( "joe                                                                               b", 
						"huqprwahfiuwfiwhfelawehflauwhfliauwehfliauhwelfiuawlfiuahewfiluaewhfiuahwaiuwefhiaw                                                                                            ", 
						"444 5th avenue west                                                          afsdasdf", 
						"333-444-5555                                                 ",  
						"jhu44@ss.com.......................................................................", 
						"18/08/20021111111111111111", "444 2344 5678                  ", 
						"SPELUNKYcccccccc                                                                                                                                                          " );
	insertIndex = A1.FindNextContact(*F3p); 
	A1.InsertContact(F3p, insertIndex);
	
	//FamilyMember all strings OK
	FamilyMember *FM1p = NULL;
	FM1p = new FamilyMember( "suzy", "wu", "99 fern road", "222 5432 7766",  "123swu@abc.edu", "25/03/1990","sister in law" );
	insertIndex = A1.FindNextContact(*FM1p); 
	A1.InsertContact(FM1p, insertIndex);

	//FamilyMember all strings with invalid characters
	FamilyMember *FM2p = NULL;
	FM2p = new FamilyMember( ",suzy", "?wu", "/99 fern road", "@222 5432 7766",  "?123swu@abc.edu", " 25/03/1990","#sister in law" );
	insertIndex = A1.FindNextContact(*FM2p); 
	A1.InsertContact(FM2p, insertIndex);

	//FamilyMember all strings too long
	FamilyMember *FM3p;
	FM3p = new FamilyMember( "suzy", "wu", "99 fern road", "222 5432 7766",  "123swu@abc.edu", "25/03/1990","sister in law" );
	insertIndex = A1.FindNextContact(*FM3p); 
	A1.InsertContact(FM3p, insertIndex);
	
	//default Contact
	Contact *C4p = NULL;
	C4p = new Contact();	
	insertIndex = A1.FindNextContact(*C4p); 
	A1.InsertContact(C4p, insertIndex);

	BusinessContact *B4p = NULL;
	B4p = new BusinessContact();
	insertIndex = A1.FindNextContact(*B4p); 
	A1.InsertContact(B4p, insertIndex);
	
	Friend *F4p = NULL;
	F4p = new Friend();
	insertIndex = A1.FindNextContact(*F4p);
	A1.InsertContact(F4p, insertIndex);

	FamilyMember *FM4p = NULL;
	FM4p = new FamilyMember();
	insertIndex = A1.FindNextContact(*FM4p); 
	A1.InsertContact(FM4p, insertIndex);

	cout << endl << "address book printing using <<: not polymorphic" << endl;
	cout << "only contact information printed" << endl << endl;
	cout << A1 << endl << endl << endl;


	AddressBook B;
	AddressBook C(A1);

	cout <<  endl << endl << "copy constructor test" << endl;
	cout << "results printed using polymorphic print function " << endl;
	C.print();

	cout << "copied address book printing,  using =" << endl;
	B = A1;
	B.print();

	A1.RemoveContact(F1p);
	A1.RemoveContact(C2p);
	A1.RemoveContact(FM3p);
	{
		BusinessContact Bx(*B3p);
		A1.RemoveContact(B3p);
		A1.RemoveContact(&Bx);
	}

	cout << "address book after removing F1p, C2p, FM3p, and B3p" << endl;
	cout << "printed using print()" << endl << endl;
	A1.print();

	//testing ==
	if (C == B ) cout << "address books B and C are identical" << endl;
	if (!(A1 == B) )cout << "address book A1 is not identical to C,"
		                 << " some elements have been deleted" << endl; 
	cout << endl << endl << endl;

	//testing accessors and mutator
	cout << "actual number of contacts in address book is ";
	cout << C.GetActualNumberContacts() << endl;
	cout << "max number of contacts in address book is ";
	cout << C.GetMaxNumberContacts() << endl;
	cout << "pointer to array of pointers to contacts " 
		 << C.GetAddressBookPointer() << endl;
	C.SetMaxNumberContacts(35);
	cout << "after mutator changes max number to 35" << endl;
	cout << "actual number of contacts in address book is ";
	cout << C.GetActualNumberContacts() << endl;
	cout << "max number of contacts in address book is ";
	cout << C.GetMaxNumberContacts() << endl;
	unsigned int kend = C.GetActualNumberContacts();
	for ( unsigned int k=kend; k< kend*2; k++)
	{ 
	    insertIndex = C.FindNextContact(*(  *(B.GetAddressBookPointer() + k - kend ) ));
		 C.InsertContact( (  *(B.GetAddressBookPointer() + k - kend ) )->CopyObject(  ), insertIndex);
	}
	cout << "after adding 16 more contacts " << endl;
	cout << endl << endl;
	C.print();
	cout << endl << endl;
	C.SetMaxNumberContacts(10);	
	cout << "after mutator tries to change max number to 10" << endl;
	cout << "actual number of contacts in address book is ";
	cout << C.GetActualNumberContacts() << endl;
	cout << "max number of contacts in address book is ";
	cout << C.GetMaxNumberContacts() << endl;
	C.SetMaxNumberContacts(20);	
	cout << "after mutator changes max number to 20" << endl;
	cout << "actual number of contacts in address book is ";
	cout << C.GetActualNumberContacts() << endl;
	cout << "max number of contacts in address book is ";
	cout << C.GetMaxNumberContacts() << endl;
	C.print();
	cout << endl << endl;


	
//	C.~AddressBook();
//	A1.~AddressBook();
//	B.~AddressBook();
	
	return 0;
}
