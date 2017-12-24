#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <vector>
#include <memory>
#include "Contact.h"
#include "Friend.h"
#include "BusinessContact.h"
#include "FamilyMember.h"

using namespace std;

class AddressBook
{
public:
	using array_type=vector<shared_ptr<Contact>>;
	using size_type=vector<shared_ptr<AddressBook>>::size_type;

	AddressBook();
	AddressBook(const AddressBook& toCopy);

	void SetMaxNumberContacts(size_type maxNumberContactsValue);
	AddressBook &operator =(const AddressBook &toCopy);
	bool operator ==(const AddressBook &right) const;

	void Print()const;

	size_type FindNextContact(const Contact &contact)const;
	size_type FindNextContact(Contact &&contact)const;

	bool InsertContact(Contact &&contact, size_type insertAtIndex);
	bool InsertContact(const Contact *contact, size_type insertAtIndex);
	bool InsertContact(const Contact &contact, size_type insertAtIndex);

	bool RemoveContact(const Contact &contact);

	~AddressBook();

private:
	bool ExtendArray(size_type newSize);
	bool ShrinkArray(size_type newSize);

	vector<shared_ptr<Contact>> array;
};


#endif // ADDRESSBOOK_H
