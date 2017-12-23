#include "BusinessContact.h"
#include "Contact.h"
#include <iomanip>

const string companyOKCharacters =
    "0123456789 ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
const string positionOKCharacters =
    "0123456789 ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
const string workingHoursOKCharacters =
    "0123456789 -:ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
constexpr int maxLengthCompany = 128;
constexpr int maxLengthPosition = 128;
constexpr int maxLengthWorkingHours = 128;
int BusinessContact::numberBusinessContacts = 0;

BusinessContact::BusinessContact() : Contact()
{
  company = "Enter company";
  position = "Enter Position";
  workingHours = "Enter Working Hours";

  numberBusinessContacts++;
}

BusinessContact::BusinessContact(string firstNameValue, string familyNameValue,
                                 string addressValue,
                                 string cellPhoneNumberValue,
                                 string emailAddressValue, string companyValue,
                                 string positionValue, string workingHoursValue)
    : Contact(firstNameValue, familyNameValue, addressValue,
              cellPhoneNumberValue, emailAddressValue)
{
  company = this->CheckCorrectString(companyOKCharacters, maxLengthCompany,
                                     companyValue);
  position = this->CheckCorrectString(positionOKCharacters, maxLengthPosition,
                                      positionValue);
  workingHours = this->CheckCorrectString(
      workingHoursOKCharacters, maxLengthWorkingHours, workingHoursValue);
  numberBusinessContacts++;
}

BusinessContact::BusinessContact(string firstNameValue, string familyNameValue)
    : Contact(firstNameValue, familyNameValue)
{
  company = "Enter Company";
  position = "Enter Position";
  workingHours = "Enter Working Hours";

  numberBusinessContacts++;
}

BusinessContact::BusinessContact(const BusinessContact &contactToBeCopied)
    : Contact(contactToBeCopied)
{
  company = contactToBeCopied.company;
  position = contactToBeCopied.position;
  workingHours = contactToBeCopied.workingHours;

  numberBusinessContacts++;
}

BusinessContact::~BusinessContact() { numberBusinessContacts--; }

string BusinessContact::GetCompany() const { return this->company; }
string BusinessContact::GetPosition() const { return this->position; }
string BusinessContact::GetWorkingHours() const { return this->workingHours; }
int BusinessContact::GetNumberBusinessContacts()
{
  return BusinessContact::numberBusinessContacts;
}

void BusinessContact::SetCompany(const string companyValue)
{
  this->company =
      CheckCorrectString(companyOKCharacters, maxLengthCompany, companyValue);
}

void BusinessContact::SetPosition(const string positionValue)
{
  this->position = CheckCorrectString(positionOKCharacters, maxLengthPosition,
                                      positionValue);
}
void BusinessContact::SetWorkingHours(const string workingHoursValue)
{
  this->workingHours = CheckCorrectString(
      workingHoursOKCharacters, maxLengthWorkingHours, workingHoursValue);
}

void BusinessContact::SetNumberBusinessContacts(
    int numberBusinessContactValue)
{
  if (numberBusinessContacts >= 0)
  {
    BusinessContact::numberBusinessContacts = numberBusinessContactValue;
  }
}

BusinessContact &BusinessContact::operator=(
    const BusinessContact &rightBusinessContact)
{
  Contact::operator=(rightBusinessContact);
  this->company = rightBusinessContact.company;
  this->position = rightBusinessContact.position;
  this->workingHours = rightBusinessContact.workingHours;

  return *this;
}
bool BusinessContact::operator==(
    const BusinessContact &rightBusinessContact) const
{
  return Contact::operator==(rightBusinessContact) && this->company == rightBusinessContact.company &&
         this->position == rightBusinessContact.position &&
         this->workingHours == rightBusinessContact.workingHours;
}

ostream &operator<<(ostream &os, const BusinessContact &oneBusinessContact)
{
  os << oneBusinessContact.firstName << "  " << oneBusinessContact.familyName
     << endl;
  os << oneBusinessContact.address << endl;
  os << setw(27) << "Cell  " << oneBusinessContact.cellPhoneNumber << endl;
  os << setw(27) << "EmailAddress " << oneBusinessContact.emailAddress << endl;
  os << setw(27) << "Number of Contacts " << oneBusinessContact.numberContacts << endl;
  os << setw(27) << "Company " << oneBusinessContact.company << endl;
  os << setw(27) << "Position " << oneBusinessContact.position << endl;
  os << setw(27) << "Working Hours " << oneBusinessContact.workingHours << endl;
  os << setw(27) << "Number of BusinessContacts "
     << oneBusinessContact.numberBusinessContacts << endl;
  os << setw(27) << endl;

  return os;
}

void BusinessContact::Print() const { std::cout << *this; }

Contact *BusinessContact::CopyObject() const
{
  Contact *res = nullptr;
  try
  {
    res = new BusinessContact(*this);
  }
  catch (bad_alloc &e)
  {
    cout << "BusinessContact allocation failed" << endl;
    exit(1);
  }
  return res;
}