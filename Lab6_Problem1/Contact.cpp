#include "Contact.h"
#include <cctype>
#include <iomanip>
#include <typeinfo>
using std::string;
using std::cin;
using std::endl;

int Contact::numberContacts = 0;

/*
 * Valid characters and lengths of members
 */
static const string name_valid="QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm- ";
static constexpr unsigned int name_length=64;
static const string address_valid="QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm0123456789- ";
static constexpr unsigned int address_length=128;
static const string phone_valid="0123456789- ";
static constexpr unsigned int phone_length=16;
static const string email_valid="QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm0123456789@.";
static constexpr unsigned int email_length=64;

Contact::Contact():
    familyName("Enter Family Name"),
    firstName("Enter First Name"),
    address("Enter Address"),
    cellPhoneNumber(16, '0'),
    emailAddress("Enter email")
{
	++numberContacts;
}

Contact::Contact(string firstNameValue, string familyNameValue, string addressValue, string cellPhoneNumberValue, string emailAddressValue):
    familyName(CheckCorrectString(name_valid,name_length,familyNameValue)),
    firstName(CheckCorrectString(name_valid,name_length,firstNameValue)),
    address(CheckCorrectString(address_valid,address_length,addressValue)),
    cellPhoneNumber(CheckCorrectString(phone_valid,phone_length,cellPhoneNumberValue)),
    emailAddress(CheckCorrectString(email_valid,email_length,emailAddressValue))
{
	++numberContacts;
}

Contact::Contact(string firstNameValue, string familyNameValue):
    familyName(CheckCorrectString(name_valid,name_length,familyNameValue)),
    firstName(CheckCorrectString(name_valid,name_length,firstNameValue)),
    address("Enter Address"),
    cellPhoneNumber(16, '0'),
    emailAddress("Enter email")
{
	++numberContacts;
}

Contact::Contact(const Contact &contactToBeCopied):
    familyName(contactToBeCopied.familyName),
    firstName(contactToBeCopied.firstName),
    address(contactToBeCopied.address),
    cellPhoneNumber(contactToBeCopied.cellPhoneNumber),
    emailAddress(contactToBeCopied.emailAddress)
{
	++numberContacts;
}

Contact::~Contact()
{
	--numberContacts;
}

string Contact::GetFirstName() const
{
	return firstName;
}

string Contact::GetFamilyName() const
{
	return familyName;
}

string Contact::GetAddress() const
{
	return address;
}

string Contact::GetCellPhoneNumber() const
{
	return cellPhoneNumber;
}

string Contact::GetEmailAddress() const
{
	return emailAddress;
}

int Contact::GetNumberContacts()
{
	return numberContacts;
}

void Contact::SetFirstName(const string firstNameValue)
{
	firstName=CheckCorrectString(name_valid,name_length,firstNameValue);
}

void Contact::SetFamilyName(const string familyNameValue)
{
	familyName=CheckCorrectString(name_valid,name_length,familyNameValue);
}

void Contact::SetAddress(const string addressValue)
{
	address=CheckCorrectString(address_valid,address_length,addressValue);
}

void Contact::SetCellPhoneNumber(const string cellPhoneNumberValue)
{
	cellPhoneNumber=CheckCorrectString(phone_valid,phone_length,cellPhoneNumberValue);
}

void Contact::SetEmailAddress(const string emailAddressValue)
{
	emailAddress=CheckCorrectString(email_valid,email_length,emailAddressValue);
}

void Contact::SetNumberContacts(int numberContactsValue)
{
	numberContacts=numberContactsValue;
}

Contact &Contact::operator=(const Contact &rightContact)
{
	this->firstName=rightContact.firstName;
	this->familyName=rightContact.familyName;
	this->address=rightContact.address;
	this->cellPhoneNumber=rightContact.cellPhoneNumber;
	this->emailAddress=rightContact.emailAddress;

	return *this;
}

bool Contact::operator ==(const Contact &rightContact) const
{
	if(typeid(*this)!=typeid(rightContact)){
		return false;
	}

	return firstName==rightContact.firstName&&
	        familyName==rightContact.familyName&&
	        address==rightContact.address&&
	        cellPhoneNumber==rightContact.cellPhoneNumber&&
	        emailAddress==rightContact.emailAddress;
}

bool Contact::operator >(const Contact &rightContact) const
{
	if(!(firstName==rightContact.firstName)){
		return firstName>rightContact.firstName;
	}
	if(!(familyName==rightContact.familyName)){
		return familyName>rightContact.familyName;
	}
	if(!(address==rightContact.address)){
		return address>rightContact.address;
	}
	if(!(cellPhoneNumber==rightContact.cellPhoneNumber)){
		return cellPhoneNumber>rightContact.cellPhoneNumber;
	}
	if(!(emailAddress==rightContact.emailAddress)){
		return emailAddress>rightContact.emailAddress;
	}

	return false;
}

bool Contact::operator <(const Contact &rightContact) const
{
	if(!(firstName==rightContact.firstName)){
		return firstName<rightContact.firstName;
	}
	if(!(familyName==rightContact.familyName)){
		return familyName<rightContact.familyName;
	}
	if(!(address==rightContact.address)){
		return address<rightContact.address;
	}
	if(!(cellPhoneNumber==rightContact.cellPhoneNumber)){
		return cellPhoneNumber<rightContact.cellPhoneNumber;
	}
	if(!(emailAddress==rightContact.emailAddress)){
		return emailAddress<rightContact.emailAddress;
	}

	return false;
}

ostream &operator <<(ostream &os, const Contact &oneContact)
{
	os<<left;
	os<<oneContact.firstName<<' '<<oneContact.familyName<<'\n';
	os<<oneContact.address<<'\n';
	os<<std::setw(27)<<"Cell"<<oneContact.cellPhoneNumber<<'\n';
	os<<std::setw(27)<<"EmailAddress"<<oneContact.emailAddress<<'\n';
	os<<std::setw(27)<<"Number of Contacts"<<oneContact.numberContacts<<endl;
	os<<right;
	return os;
}

void Contact::Print() const
{
	cout<<*this;
}

Contact *Contact::CopyObject() const
{
	return new Contact(*this);
}

string Contact::CheckCorrectString(string OKCharacters, unsigned int maxLength, const string stringToCheck)
{
	string rev;
	char *temp=nullptr;
	decltype(maxLength) cnt=0;

	try{
		temp=new char[maxLength];
		for(auto c:stringToCheck){//check in order
			if(OKCharacters.find(c)!=OKCharacters.npos){//Not a valid one
				temp[cnt++]=c;
				if(cnt==maxLength){//truncated surplus part
					break;
				}
			}
		}
		temp[cnt]=0;
		rev=temp;
	}
	catch(...){
		delete[] temp;
		throw;
	}

	delete[] temp;

	return rev;
}
