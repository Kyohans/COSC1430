#include "merchant.h"

using namespace std;

#ifndef MerchantGuild_h
#define MerchantGuild_h

class MerchantGuild
{
    private:
        Merchant *members;
        int guildSize;
        int numMem;
    public:
        MerchantGuild();
        MerchantGuild(int size);
        MerchantGuild(const MerchantGuild &copy);
        ~MerchantGuild();
        MerchantGuild &operator=(const MerchantGuild &other);
        void addMember(Merchant newM);
        Merchant *getMembers();
};

#endif
