objects = Contact.o BusinessContact.o FamilyMember.o Friend.o AddressBook.o test.o
test : $(objects)
	g++ $(objects) -o test -std=c++11 
Contact.o : Contact.cpp Contact.h 
	g++ -c Contact.cpp -std=c++11 
BusinessContact.o : BusinessContact.cpp BusinessContact.h Contact.h 
	g++ -c BusinessContact.cpp -std=c++11 
FamilyMember.o : FamilyMember.cpp FamilyMember.h Contact.h
	g++ -c FamilyMember.cpp -std=c++11
Friend.o : Friend.cpp Friend.h Contact.h
	g++ -c Friend.cpp -std=c++11
AddressBook.o : AddressBook.cpp AddressBook.h Contact.h 
	g++ -c AddressBook.cpp -std=c++11
test.o : test.cpp Contact.h BusinessContact.h FamilyMember.h Friend.h AddressBook.h
	g++ -c test.cpp -std=c++11 

