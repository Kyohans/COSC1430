#include "Phonebook.h"

Phonebook::Phonebook(const int _size) : size(_size), numContacts(0)
{
    contacts = new GenericContact *[size];
    for (int i = 0; i < size; i++)
        contacts[i] = nullptr;
}

Phonebook::Phonebook(const Phonebook &origOBJ) : size(origOBJ.size), numContacts(origOBJ.numContacts)
{

    contacts = new GenericContact *[size];
    for (int i = 0; i < size; i++)
        contacts[i] = nullptr;
    for (int i = 0; i < size; i++)
    {
        if (origOBJ.contacts[i] != nullptr)
        {
            if (origOBJ.contacts[i]->getType() == "B")
            {
                BusinessContact temp = *((BusinessContact *)origOBJ.contacts[i]);
                contacts[i] = new BusinessContact;
                *((BusinessContact *)contacts[i]) = temp;
            }
            else
            {
                PersonalContact temp = *((PersonalContact *)origOBJ.contacts[i]);
                contacts[i] = new PersonalContact;
                *((PersonalContact *)contacts[i]) = temp;
            }
        }
    }
}

const Phonebook &Phonebook::operator=(const Phonebook &ObjToCopy)
{
    if (this != &ObjToCopy)
    {
        for (int i = 0; i < size; i++)
        {
            if (contacts[i] != nullptr)
            {
                delete contacts[i];
                contacts[i] = nullptr;
            }
        }
        delete[] contacts;
        contacts = nullptr;
        size = ObjToCopy.size;
        numContacts = ObjToCopy.numContacts;
        contacts = new GenericContact *[size];
        for (int i = 0; i < size; i++)
            contacts[i] = nullptr;
        for (int i = 0; i < size; i++)
        {
            if (ObjToCopy.contacts[i] != nullptr)
            {
                if (ObjToCopy.contacts[i]->getType() == "B")
                {
                    BusinessContact temp = *((BusinessContact *)ObjToCopy.contacts[i]);
                    contacts[i] = new BusinessContact;
                    *((BusinessContact *)contacts[i]) = temp;
                }
                else
                {
                    PersonalContact temp = *((PersonalContact *)ObjToCopy.contacts[i]);
                    contacts[i] = new PersonalContact;
                    *((PersonalContact *)contacts[i]) = temp;
                }
            }
        }
    }
    return *this;
}

int Phonebook::findAvailablePosition()
{
    for (int i = 0; i < size; i++)
        if (contacts[i] == nullptr)
            return i;
    return -1;
}

int Phonebook::findContactPosition(const string &_phoneNumber)
{
    for (int i = 0; i < size; i++)
        if (contacts[i] != nullptr && contacts[i]->getPhoneNumber() == _phoneNumber)
            return i;
    return -1;
}


bool Phonebook::readFromFile(const string &filename)
{
    ifstream inputFile(filename);
    if (inputFile.is_open() == true)
    {
        string temp;
        while (getline(inputFile, temp))
        {
            stringstream line(temp);
            string type, contactInfo;
            line >> type;
            getline(line, contactInfo);
            addContact(type, contactInfo);
        }
        inputFile.close();
        return true;
    }
    return false;
}

bool Phonebook::operator==(const Phonebook &RHS)
{
    int counter = 0;
    if (size == RHS.size && numContacts == RHS.numContacts)
    {
        for (int i = 0; i < size; i++)
        {
            if (contacts[i] != nullptr && RHS.contacts[i] != nullptr && contacts[i]->getType() == RHS.contacts[i]->getType())
            {
                if (*contacts[i] != *RHS.contacts[i])
                    return false;
                counter++;
            }
            else
                return false;
            if (counter == numContacts)
                break;
        }
    }
    else
        return false;
    return true;
}

Phonebook::~Phonebook()
{
    for (int i = 0; i < size; i++)
    {
        if (contacts[i] != nullptr)
        {
            delete contacts[i];
            contacts[i] = nullptr;
        }
    }
    delete[] contacts;
    contacts = nullptr;
}

bool Phonebook::addContact(const string &type, const string &_contactInformation)
{
    // Write the implementation of the addContact member function here
    if(numContacts >= size)
    {
        cout << "Cannot add the personal contact. The phonebook is full" << endl;
        return false;
    }

    if(type == "B")
    {
        BusinessContact *business = new BusinessContact();
        string temp;
        stringstream s(_contactInformation);

        s >> temp;
        business->setBName(temp);

        s >> temp;
        business->setCity(temp);

        s >> temp;
        business->setEmail(temp);

        s >> temp;
        business->setPhoneNumber(temp);

        contacts[numContacts] = business;
        numContacts++;
        return true;
    }
    else if(type == "P")
    {
        PersonalContact *personal = new PersonalContact();
        string temp;
        stringstream s(_contactInformation);

        s >> temp;
        personal->setFName(temp);

        s >> temp;
        personal->setLName(temp);

        s >> temp;
        personal->setDOB(temp);

        s >> temp;
        personal->setEmail(temp);

        s >> temp;
        personal->setPhoneNumber(temp);

        contacts[numContacts] = personal;
        numContacts++;
        return true;
    }
}

bool Phonebook::deleteContact(const string &_phoneNumber)
{
    // Write the implementation of the delete member function here
    int pos = -1;
    for(int i = 0; i < numContacts; i++)
    {
        if(contacts[i]->getPhoneNumber() == _phoneNumber)
        {
            pos = i;
        }
    }

    if(pos == -1)
    {
        cout << "Cannot find the phone number in the phonebook" << endl;
        return false;
    }

    for(int i = pos; i < numContacts; i++)
    {
        contacts[i] = contacts[i+1];
    }

    numContacts--;
    return true;
}

void Phonebook::print() const
{
    cout << "Contacts: " << endl;
    // Write the implementation of the print member function here
    for(int i = 0; i < numContacts; i++)
        contacts[i]->print();

}

