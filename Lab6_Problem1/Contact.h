#ifndef ContactFlag
#define ContactFlag

#include <iostream>
#include <string>

using namespace std;

class Contact
{
public:
	Contact();
	Contact(string firstNameValue, string familyNameValue, string addressValue,
	        string cellPhoneNumberValue, string emailAddressValue);
	Contact(string firstNameValue, string familyNameValue);
	Contact(const Contact& contactToBeCopied);
	virtual ~Contact();///Problem?
	string GetFirstName( ) const;
	string GetFamilyName( ) const;
	string GetAddress( ) const;
	string GetCellPhoneNumber( ) const;
	string GetEmailAddress( ) const;
	static int GetNumberContacts();
	void SetFirstName( const string firstNameValue);
	void SetFamilyName( const string familyNameValue);
	void SetAddress( const string addressValue);
	void SetCellPhoneNumber( const string cellPhoneNumberValue);
	void SetEmailAddress( const string emailAddressValue);
	static void SetNumberContacts(int numberContactsValue);
	Contact &operator= (const Contact& rightContact);
	virtual bool operator == (const Contact& rightContact) const;///Problem?
	bool operator > (const Contact& rightContact) const;
	bool operator < (const Contact& rightContact) const;
	friend ostream &operator <<
	(ostream& os, const Contact& oneContact);
	virtual void Print() const;
	virtual Contact* CopyObject( ) const;
	

protected:
	string CheckCorrectString( string OKCharacters,
	                           unsigned int maxLength, const string stringToCheck );
	string familyName;
	string firstName;
	string address;
	string cellPhoneNumber;
	string emailAddress;
	static int numberContacts;
};

#endif
