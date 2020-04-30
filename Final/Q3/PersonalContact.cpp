#include "PersonalContact.h"

PersonalContact::PersonalContact() : GenericContact(), fname(""), lname(""), dob("")
{
}

PersonalContact::PersonalContact(const string &_fname, const string &_lname, const string &_dob, const string &_email, const string &_phoneNumber) : GenericContact("P", _email, _phoneNumber), fname(_fname), lname(_lname), dob(_dob)
{
}

string PersonalContact::getFName()
{
    return fname;
}

string PersonalContact::getLName()
{
    return lname;
}

string PersonalContact::getDOB()
{
    return dob;
}

void PersonalContact::setFName(const string &_fname)
{
    fname = _fname;
}

void PersonalContact::setLName(const string &_lname)
{
    lname = _lname;
}

void PersonalContact::setDOB(const string &_dob)
{
    dob = _dob;
}

void PersonalContact::print() const
{
    cout << "Firstname: " << fname << ", Lastname: " << lname << ", DOB: " << dob << " ";
    GenericContact::print();
}

bool PersonalContact::operator!=(const GenericContact &contact)
{
    PersonalContact &temp = (PersonalContact &)contact;
    if (lname != temp.lname || fname != temp.fname || dob != temp.dob || getType() != temp.getType() || getEmail() != temp.getEmail() || getPhoneNumber() != temp.getPhoneNumber())
        return true;
    return false;
}
