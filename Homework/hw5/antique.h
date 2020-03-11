#ifndef ANTIQUE_H
#define ANTIQUE_H

#include <string>
#include <sstream>
using namespace std;

class Antique
{
    private:
        string name;
        float price;
    public:
        Antique(string n = "", float p = 0);
        Antique(const Antique& baseAntique);
        Antique operator+(Antique& rhs);
        bool operator==(const Antique& rhs);
        void setName(string n);
        void setPrice(float p);
        const string getName();
        float getPrice();
        const string toString();
};

#endif