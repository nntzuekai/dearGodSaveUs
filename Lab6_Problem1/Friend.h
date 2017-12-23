#ifndef FriendFlag
#define FriendFlag

#include <iostream>
#include <string>
#include "Contact.h"

using namespace std;

class Friend: public Contact
{
public:
	Friend();
	Friend(string firstNameValue, string familyNameValue, string address,
	       string cellPhoneNumberValue,string emailAddressValue, string birthday,
	       string homePhoneNumber, string ChatAccountName);
	Friend(string firstNameValue, string familyNameValue);
	Friend(const Friend& friendToBeCopied);
	~Friend();
	string GetBirthday( ) const;
	string GetHomePhoneNumber( ) const;
	string GetChatAccountName() const;
	static int GetNumberFriends();
	void SetBirthday( const string birthdayValue);
	void SetHomePhoneNumber( const string homePhoneNumberValue);
	void SetChatAccountName( const string chatAccountNameValue);
	static void SetNumberFriends( int numberFriendsValue);
	Friend &operator = (const Friend& rightContact);
	virtual bool operator == (const Contact& rightContact) const override;
	friend ostream &operator <<
	(ostream& os, const Friend& oneFriend);
	void Print() const;
	Contact* CopyObject() const;

private:
	string birthday;
	string homePhoneNumber;
	string chatAccountName;
	static int numberFriends;
};

#endif
