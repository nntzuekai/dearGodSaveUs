#include "FamilyMember.h"
#include <iomanip>
using std::string;
using std::cin;
using std::endl;

/*
 * Valid characters and lengths of members
 */
static const string birthday_valid="0123456789/";
static constexpr unsigned int birthday_length=16;
static const string name_valid="QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm- ";
static constexpr unsigned int name_length=64;

int FamilyMember::numberFamilyMembers = 0;

FamilyMember::FamilyMember():
    Contact(),
    birthday("00/00/0000"),
    relationship("Enter relationship")
{
	++numberFamilyMembers;
}

FamilyMember::FamilyMember(string firstNameValue, string familyNameValue, string address, string cellPhoneNumberValue, string emailAddressValue, string birthday, string relationship):
    Contact(firstNameValue,familyNameValue,address,cellPhoneNumberValue,emailAddressValue),
    birthday(CheckCorrectString(birthday_valid,birthday_length,birthday)),
    relationship(CheckCorrectString(name_valid,name_length,relationship))
{
	++numberFamilyMembers;
}

FamilyMember::FamilyMember(string firstNameValue, string familyNameValue):
    Contact(firstNameValue,familyNameValue),
    birthday("00/00/0000"),
    relationship("Enter relationship")
{
	++numberFamilyMembers;
}

FamilyMember::FamilyMember(const FamilyMember &FamilyMemberToBeCopied):
    Contact(FamilyMemberToBeCopied),
    birthday(FamilyMemberToBeCopied.birthday),
    relationship(FamilyMemberToBeCopied.relationship)
{
	++numberFamilyMembers;
}

FamilyMember::~FamilyMember()
{
	--numberFamilyMembers;
}

string FamilyMember::GetBirthday() const
{
	return birthday;
}

string FamilyMember::GetRelationship() const
{
	return relationship;
}

int FamilyMember::GetNumberFamilyMembers()
{
	return numberFamilyMembers;
}

void FamilyMember::SetBirthday(const string birthdayValue)
{
	birthday=CheckCorrectString(birthday_valid,birthday_length,birthdayValue);
}

void FamilyMember::SetRelationship(const string relationshipValue)
{
	relationship=CheckCorrectString(name_valid,name_length,relationshipValue);
}

void FamilyMember::SetNumberFamilyMembers(int numberFamilyMembersValue)
{
	numberFamilyMembers=numberFamilyMembersValue;
}

FamilyMember &FamilyMember::operator =(const FamilyMember &rightContact)
{
	this->Contact::operator =(rightContact);//Base part
	birthday=rightContact.birthday;
	relationship=rightContact.relationship;

	return *this;
}

bool FamilyMember::operator ==(const Contact &rightContact) const
{
	if(auto rhs=dynamic_cast<const FamilyMember*>(&rightContact)){
		return this->Contact::operator ==(rightContact)&&//Base part
		        birthday==rhs->birthday&&
		        relationship==rhs->relationship;
	}
	else{
		return false;
	}

}

void FamilyMember::Print() const
{
	cout<<*this;
}

Contact *FamilyMember::CopyObject() const
{
	return new FamilyMember(*this);
}

ostream &operator <<(ostream &os, const FamilyMember &oneFamilyMember)
{
	os<<static_cast<const Contact&>(oneFamilyMember);
	os<<left;
	os<<setw(27)<<"Birthday"<<oneFamilyMember.birthday<<'\n';
	os<<setw(27)<<"Relationship"<<oneFamilyMember.relationship<<'\n';
	os<<setw(27)<<"Number of FamilyMembers"<<oneFamilyMember.numberFamilyMembers<<endl;
	os<<right;
	return os;
}
