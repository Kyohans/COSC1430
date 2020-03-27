#include "MerchantGuild.h"
#include <iostream>

using namespace std;

/*
    Constructor:
    Creates MerchantGuild object
    Sets size of guild to 10 and creates a dynamic array of Merchant objects
    Initial amount of members is set to zero
*/
MerchantGuild::MerchantGuild()
{
    guildSize = 10;
    members = new Merchant[guildSize];
    numMem = 0;
}

/*
    Constructor:
    Similar to noarg constructor, but allows the user to specify size of guild
*/
MerchantGuild::MerchantGuild(int size)
{
    if(size < 1)
        size = 10;
    
    guildSize = size;
    members = new Merchant[size];
    numMem = 0;
}

/*
    Copy Constructor:
    Creates a new MerchantGuild object with the data of another
*/
MerchantGuild::MerchantGuild(const MerchantGuild &copy)
{
    guildSize = copy.guildSize;
    numMem = copy.numMem;
    members = new Merchant[guildSize];

    for(int i = 0; i < guildSize; i++)
    {
        members[i] = copy.members[i];
    }
}

/*
    Assignment Operator Overload:
    Deletes contents of an existing MerchantGuild object and assigns it new data from another
*/
MerchantGuild &MerchantGuild::operator=(const MerchantGuild &other)
{
    delete[] members;

    guildSize = other.guildSize;
    numMem = other.numMem;
    members = new Merchant[guildSize];

    for (int i = 0; i < guildSize; i++)
    {
        members[i] = other.members[i];
    }

    return *this;
}

/*
    Add Member:
    Adds new member to MerchantGuild object appending members array and increases number of members by 1
*/
void MerchantGuild::addMember(Merchant newM)
{
    if(numMem == guildSize)
    {
        cout << "Guild is full." << endl;
        return;
    }

    numMem++;
    members[numMem-1] = newM;
}

/*
    Get Members:
    Retrieves pointer of member array
*/
Merchant *MerchantGuild::getMembers()
{
    return this->members;
}

/*
    Destructor:
    Deallocates dynamic array of MerchantGuild members
*/
MerchantGuild::~MerchantGuild()
{
    delete[] members;
}