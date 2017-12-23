#ifndef FamilyMemberFlag
#define FamilyMemberFlag

#include <iostream>
#include <string>
#include "Contact.h"

using namespace std;

class FamilyMember: public Contact
{
public:
	FamilyMember();
	FamilyMember(string firstNameValue, string familyNameValue, string address,
	             string cellPhoneNumberValue,string emailAddressValue, string birthday,
	             string relationship);
	FamilyMember(string firstNameValue, string familyNameValue);
	FamilyMember(const FamilyMember& FamilyMemberToBeCopied);
	~FamilyMember();
	string GetBirthday( ) const;
	string GetRelationship( ) const;
	static int GetNumberFamilyMembers();
	void SetBirthday( const string birthdayValue);
	void SetRelationship( const string relationshipValue);
	static void SetNumberFamilyMembers( int numberFamilyMembersValue);
	FamilyMember &operator = (const FamilyMember& rightContact);
	virtual bool operator == (const Contact& rightContact) const override;
	friend ostream &operator <<
	(ostream& os, const FamilyMember& oneFamilyMember);
	void Print() const;
	Contact *CopyObject() const;

private:

	string birthday;
	string relationship;
	static int numberFamilyMembers;
};

#endif
