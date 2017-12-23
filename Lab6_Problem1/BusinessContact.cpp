/*
 * Author: Huang Ruikai
 */

#include "BusinessContact.h"
#include <cctype>
#include <iomanip>
using std::string;
using std::cin;
using std::endl;

/*
 * Valid characters and lengths of members
 */
static const string name_valid="QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm- ";
static constexpr unsigned int name_length=64;
static const string hours_valid="0123456789-: ";
static constexpr unsigned int hours_length=64;

int BusinessContact::numberBusinessContacts = 0;

BusinessContact::BusinessContact():
    Contact(),
    company("Enter company"),
    position("Enter Position"),
    workingHours("Enter Working Hours")
{
	++numberBusinessContacts;
}

BusinessContact::BusinessContact(string firstNameValue, string familyNameValue, string address, string cellPhoneNumberValue, string emailAddressValue, string company, string position, string WorkingHours):
    Contact(firstNameValue,familyNameValue,address,cellPhoneNumberValue,emailAddressValue),
    company(CheckCorrectString(name_valid,name_length,company)),
    position(CheckCorrectString(name_valid,name_length,position)),
    workingHours(CheckCorrectString(hours_valid,hours_length,WorkingHours))
{
	++numberBusinessContacts;
}

BusinessContact::BusinessContact(string firstNameValue, string familyNameValue):
    Contact(firstNameValue,familyNameValue),
    company("Enter company"),
    position("Enter Position"),
    workingHours("Enter Working Hours")
{
	++numberBusinessContacts;
}

BusinessContact::BusinessContact(const BusinessContact &businessContactToBeCopied):
    Contact(businessContactToBeCopied),
    company(businessContactToBeCopied.company),
    position(businessContactToBeCopied.position),
    workingHours(businessContactToBeCopied.workingHours)
{
	++numberBusinessContacts;
}

BusinessContact::~BusinessContact()
{
	--numberBusinessContacts;
}

string BusinessContact::GetCompany() const
{
	return company;
}

string BusinessContact::GetPosition() const
{
	return position;
}

string BusinessContact::GetWorkingHours() const
{
	return workingHours;
}

int BusinessContact::GetNumberBusinessContacts()
{
	return numberBusinessContacts;
}

void BusinessContact::SetCompany(const string companyValue)
{
	company = CheckCorrectString(name_valid,name_length,companyValue);
}

void BusinessContact::SetPosition(const string positionValue)
{
	position = CheckCorrectString(name_valid,name_length,positionValue);
}

void BusinessContact::SetWorkingHours(const string workingHoursValue)
{
	workingHours=CheckCorrectString(hours_valid,hours_length,workingHoursValue);
}

void BusinessContact::SetNumberBusinessContacts(int numberBusinessContactsValue)
{
	numberBusinessContacts= numberBusinessContactsValue;
}

BusinessContact &BusinessContact::operator =(const BusinessContact &rightContact)
{
	this->Contact::operator =(rightContact);//Base part
	company=rightContact.company;
	position=rightContact.position;
	workingHours=rightContact.workingHours;
	return *this;
}

bool BusinessContact::operator ==(const Contact &rightContact) const
{
	if(auto rhs=dynamic_cast<const BusinessContact*>(&rightContact)){
		return this->Contact::operator ==(rightContact)&&//Base part
		        company== rhs->company&&
		        position== rhs->position&&
		        workingHours== rhs->workingHours;
	}
	else{
		return false;
	}
}

void BusinessContact::Print() const
{
	cout<<*this;
}

Contact *BusinessContact::CopyObject() const
{
	return new BusinessContact(*this);
}

ostream &operator <<(ostream &os, const BusinessContact &oneBusinessContact)
{
	os<<static_cast<const Contact&>(oneBusinessContact);

	os<<left;
	os<<setw(27)<<"Company"<<oneBusinessContact.company<<'\n';
	os<<setw(27)<<"Position"<<oneBusinessContact.position<<'\n';
	os<<setw(27)<<"Working hours"<<oneBusinessContact.workingHours<<'\n';
	os<<setw(27)<<"Number of BusinessContacts"<<oneBusinessContact.numberBusinessContacts<<endl;
	os<<right;
	return os;
}
