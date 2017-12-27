#include "AddressBook.h"
#include <iostream>
#include <iomanip>
#include <new>
#include <typeinfo>

/*
 * Valid characters and lengths of members
 */
static const string unable_create="Not able to create the AddressBook:";
static const string unable_change="Not able to change the AddressBook:";
static const string alloc_fail="Memory allocation failed";

using namespace std;

/*
 * Check if two contacts equals
 */
//static bool Contact_equal(const Contact *lhs, const Contact *rhs){
//	if(typeid(*lhs)!=typeid(*rhs)){//Different types
//		return false;
//	}
//	//Same types
//	if(auto bsns=dynamic_cast<const BusinessContact*>(lhs)){
//		return *bsns== *static_cast<const BusinessContact*>(rhs);
//	}
//	else if(auto fml=dynamic_cast<const FamilyMember*>(lhs)){
//		return *fml== *static_cast<const FamilyMember*>(rhs);
//	}
//	else if(auto frnd=dynamic_cast<const Friend*>(lhs)){
//		return *frnd== * static_cast<const Friend*>(rhs);
//	}
//	else{//both are Contacts
//		return *lhs==*rhs;
//	}
//}

AddressBook::AddressBook() try
{
	array.reserve(20);
}catch(bad_alloc){
	cerr<<unable_create<<endl;
	cerr<<alloc_fail<<endl;
}

AddressBook::AddressBook(const AddressBook &toCopy) try:
    array(toCopy.array.size())
{
	array.reserve(20);
	auto maxNumberContacts=array.size();
	for(size_type i=0;i<maxNumberContacts;i++){
		if(toCopy.array[i]==nullptr){
			array[i]=nullptr;
		}
		else{
			array[i].reset(toCopy.array[i]->CopyObject());
		}
	}
}catch(bad_alloc){
	cerr<<unable_create<<endl;
	cerr<<alloc_fail<<endl;
}

void AddressBook::SetMaxNumberContacts(size_type maxNumberContactsValue)
{
	bool res;

	if(array.capacity()==maxNumberContactsValue){
		return;
	}

	res= maxNumberContactsValue>array.capacity()
	     ? ExtendArray(maxNumberContactsValue)
	     : ShrinkArray(maxNumberContactsValue);//To extend or to shrink

	if(res==false){
		cerr<<unable_create<<endl;
		cerr<<alloc_fail<<endl;
	}
}

AddressBook::size_type AddressBook::GetMaxNumberContacts() const
{
	return array.capacity();
}

AddressBook::size_type AddressBook::GetActualNumberContacts() const
{
	return array.size();
}

AddressBook &AddressBook::operator =(const AddressBook &toCopy) try{
	array_type array_t(toCopy.array.size());
	array_t.reserve(toCopy.array.capacity());

	for(size_type i=0;i<array_t.size();i++){
		if(toCopy.array[i]==nullptr){
			array_t[i]=nullptr;
		}
		else{
			array_t[i].reset(toCopy.array[i]->CopyObject());
		}
	}

	array.swap(array_t);

	return *this;
}catch(bad_alloc){
	cerr<<unable_change<<endl;
	cerr<<alloc_fail<<endl;
	return *this;
}

bool AddressBook::operator ==(const AddressBook &right) const
{
	if(array.size()!=right.array.size()){
		return false;
	}
	for(size_type i=0;i<array.size();i++){
		if(!(*array[i]==*right.array[i])){
			return false;
		}
	}
	return true;
}

auto AddressBook::GetAddressBookPointer() const -> decltype (array.data())
{
	return array.data();
}

void AddressBook::print() const
{
	cout<<left;
	cout<<setw(31)<<"Maximum number of contacts"<<array.capacity()<<'\n';
	cout<<setw(31)<<"Actual number of contacts"<<array.size()<<'\n';
	cout<<setw(31)<<"Pointer to array of contacts"<<array.data()<<endl;
	cout<<"Array of Contacts:"<<'\n'<<endl;
	cout<<right;

	for(const auto &contact:array){
		contact->Print();
		cout<<'\n';
	}
}

ostream &operator<<(ostream &os, const AddressBook &addressbook)
{
	const auto &array=addressbook.array;
	os<<left;
	os<<setw(31)<<"Maximum number of contacts"<<array.capacity()<<'\n';
	os<<setw(31)<<"Actual number of contacts"<<array.size()<<'\n';
	os<<setw(31)<<"Pointer to array of contacts"<<array.data()<<endl;
	os<<"Array of Contacts:"<<'\n'<<endl;
	os<<right;

	for(const auto &contact:array){
		os<<*contact<<'\n';
	}
	return os;
}

AddressBook::size_type AddressBook::FindNextContact(const Contact &contact) const
{
	size_type i;
	for(i=0;i<array.size();i++){
		if(*array[i] > contact){
			break;
		}
	}
	return i;
}

AddressBook::size_type AddressBook::FindNextContact(Contact &&contact) const
{
	size_type i;
	for(i=0;i<array.size();i++){
		if(*array[i] > contact){
			break;
		}
	}
	return i;
}

bool AddressBook::InsertContact(Contact &&contact, size_type insertAtIndex)
{
	if(insertAtIndex>array.size()){
		return false;
	}

	if(array.size()==array.capacity()){
		if(!ExtendArray(array.capacity()+5)){//failed
			cerr<<unable_change<<endl;
			cerr<<alloc_fail<<endl;
			return false;
		}
	}

	array.insert(array.begin()+insertAtIndex,make_shared<Contact>(contact));///TODO
	return true;
}

bool AddressBook::InsertContact(const Contact &contact, size_type insertAtIndex)
{
	if(insertAtIndex>array.size()){
		return false;
	}

	if(array.size()==array.capacity()){
		if(!ExtendArray(array.capacity()+5)){//failed
			cerr<<unable_change<<endl;
			cerr<<alloc_fail<<endl;
			return false;
		}
	}

	Contact *temp=nullptr;
	try{
		temp=contact.CopyObject();
	}catch(bad_alloc){
		cerr<<unable_change<<endl;
		cerr<<alloc_fail<<endl;
		return false;
	}

	array.insert(array.begin()+insertAtIndex,make_shared<Contact>(*temp));
	return true;
}

bool AddressBook::InsertContact(const Contact *contact, size_type insertAtIndex)
{
	if(insertAtIndex>array.size()){
		return false;
	}

	if(array.size()==array.capacity()){
		if(!ExtendArray(array.capacity()+5)){//failed
			cerr<<unable_change<<endl;
			cerr<<alloc_fail<<endl;
			return false;
		}
	}

	Contact *temp=nullptr;
	try{
		temp=contact->CopyObject();
	}
	catch(bad_alloc){
		cerr<<unable_change<<endl;
		cerr<<alloc_fail<<endl;
		return false;
	}

	array.insert(array.begin()+insertAtIndex,make_shared<Contact>(*temp));
	return true;
}

bool AddressBook::RemoveContact(const Contact &contact)
{
	size_type i;
	for(i=0;i<array.size();i++){
		if(*array[i] == contact){
			break;
		}
	}
	if(i==array.size()){
		return false;
	}
	else{
		array.erase(array.begin()+i);
		return true;
	}
}

bool AddressBook::RemoveContact(const Contact *pcontact)
{
	size_type i;
	for(i=0;i<array.size();i++){
		if(*array[i] == *pcontact){
			break;
		}
	}
	if(i==array.size()){
		return false;
	}
	else{
		array.erase(array.begin()+i);
		return true;
	}
}

bool AddressBook::ExtendArray(size_type newSize)
{
	if(newSize<=array.capacity()){
		return true;
	}

	try{
		array.reserve(newSize);
	}
	catch(bad_alloc){
		return false;//failed
	}

	return true;
}

bool AddressBook::ShrinkArray(size_type newSize)
{
	if(newSize>=array.capacity()||newSize<=20){
		return true;
	}

	try{
		array.resize(newSize);
		array.shrink_to_fit();
	}
	catch(bad_alloc){
		return false;//failed
	}

	return true;
}
