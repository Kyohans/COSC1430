//include the necessary header files
#include <iostream>
#include <string>
#include "character.h"

using namespace std;

//implement constructors
Character::Character()
{
    name = "";
    race = "";
    level = 0;
    health = 0;
}
Character::Character(string name_, string race_, int level_, int health_)
{
    name = name_;
    race = race_;
    level = level_;
    health = health_;
}

//implement getter functions
string Character::getName() const
{
    return name;
}
string Character::getRace() const
{
    return race;
}

int Character::getLevel() const
{
    return level;
}

int Character::getHealth() const
{
    return health;
}

//implement setter functions
void Character::SetName(string name)
{
    this->name = name;
}

void Character::SetRace(string name)
{
    race = name;
}

void Character::SetLevel(int level)
{
    this->level = level;
}

void Character::SetHealth(int health)
{
    this->health = health;
}

//implement Print function
void Character::Print()
{
    cout << "Character Status: " << endl;
    cout << "Name: " << getName() << endl;
    cout << "Race: " << getRace() << endl;
    cout << "Level: " << getLevel() << endl;
    cout << "Health: " << getHealth() << endl;
}