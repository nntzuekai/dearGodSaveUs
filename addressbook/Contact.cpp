
#include "Contact.h"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <tuple>

int Contact::numberContacts = 0;
constexpr int maxLengthName = 64;
constexpr int maxLengthAddress = 128;
constexpr int maxLengthNumber = 16;
constexpr int maxLengthEmailAddress = 64;
const string nameOKCharacters =
    " -ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
const string addressOKCharacters =
    " -ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
const string cellPhoneNumberOKCharacters =
    "0123456789 ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
const string emailAddressOKCharacters =
    "0123456789@.ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

Contact::Contact()
    : Contact("Enter First Name", "Enter Family Name", "Enter Address",
              "0000000000000000", "Enter.email"){};

Contact::Contact(string firstNameValue, string familyNameValue,
                 string addressValue, string cellPhoneNumberValue,
                 string emailAddressValue)
    : firstName(
          CheckCorrectString(nameOKCharacters, maxLengthName, firstNameValue)),
      familyName(
          CheckCorrectString(nameOKCharacters, maxLengthName, familyNameValue)),
      address(CheckCorrectString(addressOKCharacters, maxLengthAddress,
                                 addressValue)),
      cellPhoneNumber(CheckCorrectString(
          cellPhoneNumberOKCharacters, maxLengthNumber, cellPhoneNumberValue)),
      emailAddress(CheckCorrectString(
          emailAddressOKCharacters, maxLengthEmailAddress, emailAddressValue)) {
  numberContacts++;
}

Contact::Contact(string firstNameValue, string familyNameValue)
    : Contact(firstNameValue, familyNameValue, "Enter Address",
              "0000000000000000", "Enter.email"){};

Contact::Contact(const Contact &contactToBeCopied)
    : Contact(contactToBeCopied.firstName, contactToBeCopied.familyName,
              contactToBeCopied.address, contactToBeCopied.cellPhoneNumber,
              contactToBeCopied.emailAddress){};
Contact::~Contact() { numberContacts--; }

string Contact::GetFirstName() const { return this->firstName; }
string Contact::GetFamilyName() const { return this->familyName; }
string Contact::GetAddress() const { return this->address; }
string Contact::GetCellPhoneNumber() const { return this->cellPhoneNumber; }
string Contact::GetEmailAddress() const { return this->emailAddress; }
int Contact::GetNumberContacts() { return Contact::numberContacts; }

void Contact::SetFirstName(const string firstNameValue) {
  this->firstName =
      CheckCorrectString(nameOKCharacters, maxLengthName, firstNameValue);
}

void Contact::SetFamilyName(const string familyNameValue) {
  this->familyName =
      CheckCorrectString(nameOKCharacters, maxLengthName, familyNameValue);
}

void Contact::SetAddress(const string addressValue) {
  this->address =
      CheckCorrectString(addressOKCharacters, maxLengthAddress, addressValue);
}

void Contact::SetCellPhoneNumber(const string cellPhoneNumberValue) {
  this->cellPhoneNumber = CheckCorrectString(
      cellPhoneNumberOKCharacters, maxLengthNumber, cellPhoneNumberValue);
}

void Contact::SetEmailAddress(const string emailAddressValue) {
  this->emailAddress = CheckCorrectString(
      emailAddressOKCharacters, maxLengthEmailAddress, emailAddressValue);
}

void Contact::SetNumberContacts(int numberContactsValue) {
  if (numberContactsValue >= 0) {
    Contact::numberContacts = numberContactsValue;
  }
}

bool Contact::operator==(const Contact &rhs) const {
  return this->familyName == rhs.familyName &&
         this->firstName == rhs.firstName && this->address == rhs.address &&
         this->cellPhoneNumber == rhs.cellPhoneNumber &&
         this->emailAddress == rhs.emailAddress;
}

Contact &Contact::operator=(const Contact &rightContact) {
  this->firstName = rightContact.firstName;
  this->familyName = rightContact.familyName;
  this->address = rightContact.address;
  this->emailAddress = rightContact.emailAddress;
  this->cellPhoneNumber = rightContact.cellPhoneNumber;

  return *this;
}

bool Contact::operator<(const Contact &rightContact) const {
  return tie(this->familyName, this->firstName, this->address,
             this->cellPhoneNumber, this->emailAddress) <
         tie(rightContact.familyName, rightContact.firstName,
             rightContact.address, rightContact.cellPhoneNumber,
             rightContact.emailAddress);
}

bool Contact::operator>(const Contact &rightContact) const {
  return tie(this->familyName, this->firstName, this->address,
             this->cellPhoneNumber, this->emailAddress) >
         tie(rightContact.familyName, rightContact.firstName,
             rightContact.address, rightContact.cellPhoneNumber,
             rightContact.emailAddress);
}

ostream &operator<<(ostream &os, const Contact &contact) {
  os << contact.firstName << "  " << contact.familyName << endl;
  os << contact.address << endl;
  os << setw(27) << "Cell  " << contact.cellPhoneNumber << endl;
  os << setw(27) << "Email " << contact.emailAddress << endl;
  os << setw(27) << "Number of Contacts " << Contact::numberContacts << endl;
  return os;
}

void Contact::Print() const { cout << *this; }
Contact *Contact::CopyObject() const {
  Contact *res = nullptr;
  try {
    res = new Contact(*this);
  } catch (bad_alloc &e) {
    cout << "contact Allocation failed" << endl;
    exit(1);
  }
  return res;
}

string Contact::CheckCorrectString(string OKCharacters, unsigned int maxLength,
                                   const string stringToCheck) {
  string res = stringToCheck;
  res.erase(remove_if(res.begin(), res.end(),
                      [&](const char c) -> bool {
                        return OKCharacters.find_first_of(c) == string::npos;
                      }),
            res.end());
  res.resize(maxLength);
  return res;
}