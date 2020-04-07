//include the necessary header files
#include <iostream>
#include <string>
#include "barbarian.h"

using namespace std;

//Constructor
Barbarian::Barbarian(string name, string race, int level, int health, int stamina)
{
    SetName(name);
    SetRace(race);
    SetLevel(level);
    SetHealth(health);
    this->stamina = stamina;
}

//Setter
void Barbarian::SetStamina(int stamina_)
{
    stamina = stamina_;
}

//Getter
int Barbarian::getStamina() const
{
    return stamina;
}

//Other functions
void Barbarian::EquipWeapon(string name, int damage, int stamina_cost)
{
    active_weapon.name = name;
    active_weapon.damage = damage;
    active_weapon.stamina_cost = stamina_cost;
}

void Barbarian::Attack(Character *target)
{
    if(active_weapon.name != "")
    {
        cout << getName() << " attacked " << target->getName() << " with a " << active_weapon.name << ", dealing " << active_weapon.damage << " damage." << endl;
    }  
    else
    {
        cout << "Barbarian has no weapon!" << endl; 
        return;
    }    

    if(stamina < active_weapon.stamina_cost)
    {
        cout << "Insufficient stamina points!" << endl;
        return;
    }

    stamina -= active_weapon.stamina_cost;
    int hp = target->getHealth() - active_weapon.damage;
    target->SetHealth(hp);
}

void Barbarian::Print()
{
    cout << "Character Status:" << endl;
    cout << "Name: " << getName() << endl;
    cout << "Race: " << getRace() << endl;
    cout << "Level: " << getLevel() << endl;
    cout << "Health: " << getHealth() << endl;
    cout << "Weapon: " << active_weapon.name << endl;
    cout << "---" << endl;
}

