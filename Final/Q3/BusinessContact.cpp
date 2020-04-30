#include "BusinessContact.h"

BusinessContact::BusinessContact() : GenericContact(), bName(""), city("")
{
}

BusinessContact::BusinessContact(const string &_bName, const string &_city, const string &_email, const string &_phoneNumber) : GenericContact("B", _email, _phoneNumber), bName(_bName), city(_city)
{
}

string BusinessContact::getBName()
{
    return bName;
}

string BusinessContact::getCity()
{
    return city;
}

void BusinessContact::setBName(const string &_bName)
{
    bName = _bName;
}

void BusinessContact::setCity(const string &_city)
{
    city = _city;
}

void BusinessContact::print() const
{
    cout << "Name: " << bName << ", City: " << city << " ";
    GenericContact::print();
}

bool BusinessContact::operator!=(const GenericContact &contact)
{
    BusinessContact &temp = (BusinessContact &)contact;
    if (bName != temp.bName || city != temp.city || getType() != temp.getType() || getEmail() != temp.getEmail() || getPhoneNumber() != temp.getPhoneNumber())
        return true;
    return false;
}