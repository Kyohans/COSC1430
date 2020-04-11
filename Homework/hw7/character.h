#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
using namespace std;

class Character
{
private:
    string name;
    string race;
    int level;
    int health;

public:
    //constructors
    Character();
    Character(string, string, int, int);

    //getter functions
    string getName() const;
    string getRace() const;
    int getLevel() const;
    int getHealth() const;

    //setter functions
    void SetName(string name);
    void SetRace(string name);
    void SetLevel(int level);
    void SetHealth(int health);

    //other functions
    //virtual ~Character();
    virtual void Print();
    virtual void Attack(Character *target) = 0;
};

#endif