#include "AddressBook.h"
#include <algorithm>
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cerr;
using std::endl;
using std::bad_alloc;
using std::sort;
using std::copy;
const string cons_fail = "Not able to create the AddressBook:";
const string mutate_fail = "Not able to change the AddressBook:";
const string alloc_fail = "Memory allocation failed";

static bool isPureContact(Contact *c) {
  return dynamic_cast<Friend *>(c) == nullptr &&
         dynamic_cast<FamilyMember *>(c) == nullptr &&
         dynamic_cast<BusinessContact *>(c) == nullptr;
}

AddressBook::AddressBook() try : contacts(20),
                                 actualNumberContacts(0),
                                 maxNumberContacts(20) {
} catch (bad_alloc &e) {
  cerr << cons_fail << endl;
  cerr << alloc_fail << endl;
}

AddressBook::AddressBook(const AddressBook &AddressBookValue) try
    : contacts(AddressBookValue.maxNumberContacts),
      actualNumberContacts(AddressBookValue.actualNumberContacts),
      maxNumberContacts(AddressBookValue.maxNumberContacts) {
  for (int i = 0; i < actualNumberContacts; ++i) {
    contacts[i] = AddressBookValue.contacts[i]->CopyObject();
  }
  sort(contacts.begin(), contacts.begin() + actualNumberContacts,
       [](const Contact *a, const Contact *b) -> bool { return *a < *b; });
} catch (bad_alloc &e) {
  cerr << cons_fail << endl;
  cerr << alloc_fail << endl;
}

AddressBook::~AddressBook() {
  for (auto iter = contacts.begin();
       iter != (contacts.begin() + actualNumberContacts); ++iter) {
    delete *iter;
  }
}

void AddressBook::SetMaxNumberContacts(int maxNumberContactsValue) {
  if (maxNumberContactsValue < 20) {
    return;
  }
  if (maxNumberContactsValue > this->maxNumberContacts) {
    this->ExtendArray(maxNumberContactsValue);
    this->maxNumberContacts = maxNumberContactsValue;
  } else if (maxNumberContacts < this->maxNumberContacts) {
    this->ShrinkArray(maxNumberContacts);
    this->maxNumberContacts = maxNumberContactsValue;
    if (this->actualNumberContacts > maxNumberContactsValue) {
      this->actualNumberContacts = maxNumberContactsValue;
    }
  }
}

bool AddressBook::operator==(const AddressBook &rhs) const {
  if (this->maxNumberContacts != rhs.maxNumberContacts ||
      this->actualNumberContacts != rhs.actualNumberContacts) {
    return false;
  }

  for (int i = 0; i < this->actualNumberContacts; ++i) {
    // nullptr or share the same pointer
    if (this->contacts[i] == nullptr && rhs.contacts[i] == nullptr) {
      continue;
    }
    if (this->contacts[i] == rhs.contacts[i]) {
      return false;
    }

    if (auto lhs_ptr = dynamic_cast<Friend *>(this->contacts[i])) {
      if (auto rhs_ptr = dynamic_cast<Friend *>(rhs.contacts[i])) {
        if (*lhs_ptr == *rhs_ptr) {
          continue;
        } else {
          return false;
        }
      } else {
        return false;
      }
    } else if (auto lhs_ptr = dynamic_cast<FamilyMember *>(this->contacts[i])) {
      if (auto rhs_ptr = dynamic_cast<FamilyMember *>(rhs.contacts[i])) {
        if (*lhs_ptr == *rhs_ptr) {
          continue;
        } else {
          return false;
        }
      } else {
        return false;
      }
    } else if (auto lhs_ptr =
                   dynamic_cast<BusinessContact *>(this->contacts[i])) {
      if (auto rhs_ptr = dynamic_cast<BusinessContact *>(rhs.contacts[i])) {
        if (*lhs_ptr == *rhs_ptr) {
          continue;
        } else {
          return false;
        }
      } else {
        return false;
      }
    } else {
      if (isPureContact(rhs.contacts[i])) {
        if (this->contacts[i] == rhs.contacts[i]) {
          continue;
        } else {
          return false;
        }
      } else {
        return false;
      }
    }
  }
  return true;
}
void AddressBook::Print() const {
  cout << "Maximum number of contacts     " << this->maxNumberContacts
       << std::endl;
  cout << "Actual number of contacts      " << this->actualNumberContacts
       << std::endl;
  cout << "Array of Contacts:" << endl << endl;
  for (auto iter = contacts.begin();
       iter != (contacts.begin() + actualNumberContacts); ++iter) {
    if (*iter) {
      (*iter)->Print();
      cout << endl;
    }
  }
}

int AddressBook::FindNextContact(const Contact &target) const {
  for (int i = 0; i < this->actualNumberContacts; ++i) {
    if (target > *this->contacts[i]) {
      return i;
    }
  }
  return this->actualNumberContacts;
}

bool AddressBook::InsertContact(Contact *toBeInserted, int insertAtIndex) {
  if (toBeInserted == nullptr || insertAtIndex > this->actualNumberContacts ||
      insertAtIndex <= 0) {
    return false;
  }
  if (this->actualNumberContacts == this->maxNumberContacts) {
    this->ExtendArray(this->maxNumberContacts + 5);
    this->maxNumberContacts = this->maxNumberContacts + 5;
  }
  contacts.insert(contacts.begin() + insertAtIndex, toBeInserted);
  this->actualNumberContacts++;
  return true;
}

bool AddressBook::RemoveContact(Contact *toBeRemoved) {
  if (toBeRemoved == nullptr) {
    return false;
  }
  auto Friend_ptr = dynamic_cast<Friend *>(toBeRemoved);
  auto FamilyMember_ptr = dynamic_cast<FamilyMember *>(toBeRemoved);
  auto BusinessContact_ptr = dynamic_cast<BusinessContact *>(toBeRemoved);
  int removeAtIndex = -1;
  for (int i = 0; i < this->actualNumberContacts; ++i) {
    if (Friend_ptr) {
      if (auto p = dynamic_cast<Friend *>(this->contacts[i])) {
        if (*Friend_ptr == *p) {
          delete p;
          removeAtIndex = i;
          break;
        }
      }
    } else if (FamilyMember_ptr) {
      if (auto p = dynamic_cast<FamilyMember *>(this->contacts[i])) {
        if (*FamilyMember_ptr == *p) {
          delete p;
          removeAtIndex = i;
          break;
        }
      }
    } else if (BusinessContact_ptr) {
      if (auto p = dynamic_cast<BusinessContact *>(this->contacts[i])) {
        if (*BusinessContact_ptr == *p) {
          delete p;
          removeAtIndex = i;
          break;
        }
      }
    } else {
      if (isPureContact(this->contacts[i])) {
        if (*toBeRemoved == *this->contacts[i]) {
          delete this->contacts[i];
          removeAtIndex = i;
          break;
        }
      }
    }
  }
  if (removeAtIndex != -1) {
    contacts.erase(contacts.begin() + removeAtIndex);
    this->actualNumberContacts--;
    return true;
  } else {
    return false;
  }
}

bool AddressBook::ExtendArray(int newSize) {
  if (newSize <= this->maxNumberContacts) {
    return true;
  }
  try {
    contacts.resize(newSize);
  } catch (bad_alloc &e) {
    return false;
  }
}

bool AddressBook::ShrinkArray(int newSize) {
  if (newSize <= 20 || newSize >= this->maxNumberContacts) {
    return false;
  }
  try {
    for (auto iter = contacts.begin() + newSize;
         iter != (contacts.begin() + actualNumberContacts); ++iter) {
      if (*iter) {
        delete *iter;
      }
    }
    contacts.resize(newSize);
    return true;
  } catch (bad_alloc &e) {
    return false;
  }
}