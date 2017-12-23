#include "Friend.h"
#include <cctype>
#include <iomanip>
using std::string;
using std::cin;
using std::endl;

/*
 * Valid characters and lengths of members
 */
static const string birthday_valid="0123456789/";
static constexpr unsigned int birthday_length=16;
static const string phone_valid="0123456789- ";
static constexpr unsigned int phone_length=16;
static const string name_valid="QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm- ";
static constexpr unsigned int name_length=64;

int Friend::numberFriends=0;

Friend::Friend():
    Contact(),
    birthday("00/00/0000"),
    homePhoneNumber(16,'0'),
    chatAccountName("Enter Chat Account Name")
{
	++numberFriends;
}

Friend::Friend(string firstNameValue, string familyNameValue, string address, string cellPhoneNumberValue, string emailAddressValue, string birthday, string homePhoneNumber, string ChatAccountName):
    Contact(firstNameValue,familyNameValue,address,cellPhoneNumberValue,emailAddressValue),
    birthday(CheckCorrectString(birthday_valid,birthday_length,birthday)),
    homePhoneNumber(CheckCorrectString(phone_valid,phone_length,homePhoneNumber)),
    chatAccountName(CheckCorrectString(name_valid,name_length,ChatAccountName))
{
	++numberFriends;
}

Friend::Friend(string firstNameValue, string familyNameValue):
    Contact(firstNameValue,familyNameValue),
    birthday("00/00/0000"),
    homePhoneNumber(16,'0'),
    chatAccountName("Enter Chat Account Name")
{
	++numberFriends;
}

Friend::Friend(const Friend &friendToBeCopied):
    Contact(friendToBeCopied),
    birthday(friendToBeCopied.birthday),
    homePhoneNumber(friendToBeCopied.homePhoneNumber),
    chatAccountName(friendToBeCopied.chatAccountName)
{
	++numberFriends;
}

Friend::~Friend()
{
	--numberFriends;
}

string Friend::GetBirthday() const
{
	return birthday;
}

string Friend::GetHomePhoneNumber() const
{
	return homePhoneNumber;
}

string Friend::GetChatAccountName() const
{
	return chatAccountName;
}

int Friend::GetNumberFriends()
{
	return numberFriends;
}

void Friend::SetBirthday(const string birthdayValue)
{
	birthday=CheckCorrectString(birthday_valid,birthday_length,birthdayValue);
}

void Friend::SetHomePhoneNumber(const string homePhoneNumberValue)
{
	homePhoneNumber=CheckCorrectString(phone_valid,phone_length,homePhoneNumberValue);
}

void Friend::SetChatAccountName(const string chatAccountNameValue)
{
	chatAccountName=CheckCorrectString(name_valid,name_length,chatAccountNameValue);
}

void Friend::SetNumberFriends(int numberFriendsValue)
{
	numberFriends=numberFriendsValue;
}

Friend &Friend::operator =(const Friend &rightContact)
{
	this->Contact::operator =(rightContact);//base
	birthday=rightContact.birthday;
	homePhoneNumber=rightContact.homePhoneNumber;
	chatAccountName=rightContact.chatAccountName;
	return *this;
}

bool Friend::operator ==(const Contact &rightContact) const
{
	if(auto rhs=dynamic_cast<const Friend*>(&rightContact)){
		return this->Contact::operator ==(rightContact)&&//base
		        birthday==rhs->birthday&&
		        homePhoneNumber==rhs->homePhoneNumber&&
		        chatAccountName==rhs->chatAccountName;
	}
	else{
		return false;
	}
}

void Friend::Print() const
{
	cout<<*this;
}

Contact *Friend::CopyObject() const
{
	return new Friend(*this);
}

ostream &operator <<(ostream &os, const Friend &oneFriend)
{
	os<<static_cast<const Contact&>(oneFriend);
	os<<left;
	os<<setw(27)<<"Birthday"<<oneFriend.birthday<<'\n';
	os<<setw(27)<<"Home Phone"<<oneFriend.homePhoneNumber<<'\n';
	os<<setw(27)<<"Chat Account Name" <<oneFriend.chatAccountName<<'\n';
	os<<setw(27)<<"Number of Friends" <<oneFriend.numberFriends<<endl;
	os<<right;
	return os;
}

