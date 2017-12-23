
#include "Friend.h"
#include "Contact.h"
#include <iomanip>
using std::endl;

int Friend::numberFriends = 0;
const string birthdayOKCharacters = "0123456789/";
const string homePhoneNumberOKCharacters = "0123456789 -";
const string chatAccountNameOKCharacters =
    " -ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
constexpr int maxLengthBirthday = 16;
constexpr int maxLengthHomePhoneNumber = 16;
constexpr int maxLengthChatAccoutName = 64;
Friend::Friend() : Contact()
{
  birthday = "00/00/0000";
  homePhoneNumber = "0000000000000000";
  chatAccountName = "Enter Chat Account Name";

  numberFriends++;
}

Friend::Friend(string firstNameValue, string familyNameValue,
               string addressValue, string cellPhoneNumberValue,
               string emailAddressValue, string birthdayValue,
               string homePhoneNumberValue, string chatAccountNameValue)
    : Contact(firstNameValue, familyNameValue, addressValue,
              cellPhoneNumberValue, emailAddressValue)
{
  birthday = this->CheckCorrectString(birthdayOKCharacters, maxLengthBirthday,
                                      birthdayValue);
  homePhoneNumber =
      this->CheckCorrectString(homePhoneNumberOKCharacters,
                               maxLengthHomePhoneNumber, homePhoneNumberValue);
  chatAccountName =
      this->CheckCorrectString(chatAccountNameOKCharacters,
                               maxLengthChatAccoutName, chatAccountNameValue);

  numberFriends++;
}

Friend::Friend(string firstNameValue, string familyNameValue)
    : Contact(firstNameValue, familyNameValue)
{
  birthday = "00/00/0000";
  homePhoneNumber = "0000000000000000";
  chatAccountName = "Enter Chat Account Name";

  numberFriends++;
}

Friend::Friend(const Friend &contactToBeCopied) : Contact(contactToBeCopied)
{
  birthday = contactToBeCopied.birthday;
  homePhoneNumber = contactToBeCopied.homePhoneNumber;
  chatAccountName = contactToBeCopied.chatAccountName;

  numberFriends++;
}

Friend::~Friend() { numberFriends--; }

string Friend::GetBirthday() const { return this->birthday; }
string Friend::GetChatAccountName() const { return this->chatAccountName; }
string Friend::GetHomePhoneNumber() const { return this->homePhoneNumber; }
int Friend::GetNumberFriends() { return Friend::numberFriends; }

void Friend::SetBirthday(const string birthdayValue)
{
  this->birthday = CheckCorrectString(birthdayOKCharacters, maxLengthBirthday,
                                      birthdayValue);
}
void Friend::SetHomePhoneNumber(const string homePhoneNumberValue)
{
  this->homePhoneNumber =
      CheckCorrectString(homePhoneNumberOKCharacters, maxLengthHomePhoneNumber,
                         homePhoneNumberValue);
}
void Friend::SetChatAccountName(const string chatAccountNameValue)
{
  this->chatAccountName =
      CheckCorrectString(chatAccountNameOKCharacters, maxLengthChatAccoutName,
                         chatAccountNameValue);
}

void Friend::SetNumberFriends(int numberFriends)
{
  if (numberFriends >= 0)
  {
    Friend::numberFriends = numberFriends;
  }
}

ostream &operator<<(ostream &os, const Friend &contact)
{
  os << contact.firstName << "  " << contact.familyName << endl;
  os << contact.address << endl;
  os << setw(27) << "Cell  " << contact.cellPhoneNumber << endl;
  os << setw(27) << "Email " << contact.emailAddress << endl;
  os << setw(27) << "Number of Contacts " << Contact::GetNumberContacts() << endl;
  os << setw(27) << "Birthday " << contact.birthday << endl;
  os << setw(27) << "Home Phone  " << contact.homePhoneNumber << endl;
  os << setw(27) << "Chat Account Name " << contact.chatAccountName << endl;
  os << setw(27) << "Number of Friends " << Friend::GetNumberFriends() << endl;
  return os;
}

void Friend::Print() const { std::cout << *this; }

Contact *Friend::CopyObject() const
{
  Contact *res;
  try
  {
    res = new Friend(*this);
  }
  catch (bad_alloc &e)
  {
    cout << "Friend allocation failed" << endl;
  }
  return res;
}

Friend &Friend::operator=(const Friend &rightContact)
{
  Contact::operator=(rightContact);
  this->birthday = rightContact.birthday;
  this->homePhoneNumber = rightContact.cellPhoneNumber;
  this->chatAccountName = rightContact.chatAccountName;
}

bool Friend::operator==(const Friend &rightFriend) const
{
  return Contact::operator==(rightFriend) && this->birthday == rightFriend.birthday &&
         this->homePhoneNumber == rightFriend.homePhoneNumber &&
         this->chatAccountName == rightFriend.chatAccountName;
}
