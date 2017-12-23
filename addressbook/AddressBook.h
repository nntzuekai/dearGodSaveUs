#ifndef AddressBookFlag
#define AddressBookFlag

#include <vector>
#include "BusinessContact.h"
#include "Contact.h"
#include "FamilyMember.h"
#include "Friend.h"

#define INSERT_FAIL -1
using std::vector;
class AddressBook {
 public:
  AddressBook();
  AddressBook(const AddressBook &AddressBookValue);
  ~AddressBook();

  void SetMaxNumberContacts(int maxNumberContactsValue);

  bool operator==(const AddressBook &rhs) const;

  void Print() const;

  int FindNextContact(const Contact &) const;
  bool InsertContact(Contact *toBeInserted, int insertAtIndex);
  bool RemoveContact(Contact *toBeRemoved);

 private:
  vector<Contact *> contacts;
  int actualNumberContacts;
  int maxNumberContacts;
  bool ExtendArray(int newSize);
  bool ShrinkArray(int newSize);
};

#endif