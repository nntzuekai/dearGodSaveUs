#include "FamilyMember.h"
#include "Contact.h"
#include <iomanip>
using std::endl;

int FamilyMember::numberFamilyMembers = 0;

const string birthdayOKCharacters = "0123456789/";
const string relationshipOKCharacters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz- ";
constexpr int maxLengthBirthday = 16;
constexpr int maxLengthRelationship = 64;

FamilyMember::FamilyMember() : Contact()

{
    birthday = "00/00/0000";
    relationship = "Enter Relationship";
    ++numberFamilyMembers;
}

FamilyMember::FamilyMember(const FamilyMember &contactToBeCopied) : Contact(contactToBeCopied)
{
    birthday = contactToBeCopied.birthday;
    relationship = contactToBeCopied.relationship;
    ++numberFamilyMembers;
}

FamilyMember::FamilyMember(string firstNameValue, string familyNameValue) : Contact(firstNameValue, familyNameValue)
{
    birthday = "00/00/0000";
    relationship = "Enter Relationship";
    ++numberFamilyMembers;
};

FamilyMember::FamilyMember(string firstNameValue, string familyNameValue, string addressValue,
                           string cellPhoneNumberValue, string emailAddressValue,
                           string birthdayValue, string relationshipValue)
    : Contact(firstNameValue, familyNameValue, addressValue, cellPhoneNumberValue, emailAddressValue)
{
    birthday = this->CheckCorrectString(birthdayOKCharacters, maxLengthBirthday, birthdayValue);
    relationship = this->CheckCorrectString(
        relationshipOKCharacters, maxLengthRelationship,
        relationshipValue);
    ++numberFamilyMembers;
}

FamilyMember::~FamilyMember()
{
    --numberFamilyMembers;
}

void FamilyMember::SetBirthday(const string birthdayValue)
{
    this->birthday = this->CheckCorrectString(birthdayOKCharacters, maxLengthBirthday, birthdayValue);
}

void FamilyMember::SetRelationship(const string relationshipValue)
{
    this->relationship = this->CheckCorrectString(
        relationshipOKCharacters, maxLengthRelationship,
        relationshipValue);
}

void FamilyMember::SetNumberFamilyMembers(int numberFamilyMembers)
{
    if (numberFamilyMembers >= 0)
    {
        FamilyMember::numberFamilyMembers = numberFamilyMembers;
    }
}

string FamilyMember::GetBirthday() const
{
    return this->birthday;
}

string FamilyMember::GetRelationship() const
{
    return this->relationship;
}

int FamilyMember::GetNumberFamilyMembers()
{
    return FamilyMember::numberFamilyMembers;
}

FamilyMember &FamilyMember::operator=(const FamilyMember &rhs)
{
    Contact::operator=(rhs);
    this->birthday = rhs.birthday;
    this->relationship = rhs.relationship;
    return *this;
}

bool FamilyMember::operator==(const FamilyMember &rightFamilyMember) const
{
    return Contact::operator==(rightFamilyMember) && this->birthday == rightFamilyMember.birthday &&
           this->relationship == rightFamilyMember.relationship;
}

ostream &operator<<(ostream &os, const FamilyMember &contact)
{
    os << setw(27) << contact.firstName << "  " << contact.familyName << endl;
    os << setw(27) << contact.address << endl;
    os << setw(27) << "cell  " << contact.cellPhoneNumber << endl;
    os << setw(27) << "email " << contact.emailAddress << endl;
    os << setw(27) << "number of Contacts " << Contact::GetNumberContacts() << endl;
    os << setw(27) << "birthday " << contact.birthday << endl;
    os << setw(27) << "relationship  " << contact.relationship << endl;
    os << setw(27) << "number of FamilyMembers " << FamilyMember::GetNumberFamilyMembers()
       << endl;
    return os;
}

void FamilyMember::Print() const
{
    std::cout << *this;
}

Contact *FamilyMember::CopyObject() const
{
    Contact *res;
    try
    {
        res = new FamilyMember(*this);
    }
    catch (bad_alloc &e)
    {
        cout << "FamilyMember allocation failed" << endl;
    }
    return res;
}