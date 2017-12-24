#ifndef BusinessContactFlag
#define BusinessContactFlag

#include <iostream>
#include <string>
#include "Contact.h"

using namespace std;

class BusinessContact: public Contact
{
public:
	BusinessContact();
	BusinessContact(string firstNameValue, string familyNameValue, string address,
	                string cellPhoneNumberValue,string emailAddressValue, string company,
	                string position, string WorkingHours);
	BusinessContact(string firstNameValue, string familyNameValue);
	BusinessContact(const BusinessContact& businessContactToBeCopied);
	~BusinessContact();
	string GetCompany( ) const;
	string GetPosition( ) const;
	string GetWorkingHours() const;
	static int GetNumberBusinessContacts();
	void SetCompany( const string companyValue);
	void SetPosition( const string positionValue);
	void SetWorkingHours( const string workingHoursValue);
	void SetNumberBusinessContacts( int numberBusinessContactsValue);
	BusinessContact &operator = (const BusinessContact& rightContact);
	virtual bool operator == (const Contact& rightContact) const override;
	friend ostream &operator <<
	(ostream& os, const BusinessContact& oneBusinessContact);
	void Print() const override;
	Contact *CopyObject() const override;

private:
	string company;
	string position;
	string workingHours;
	static int numberBusinessContacts;
};

#endif
