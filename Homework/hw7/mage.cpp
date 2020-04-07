//include the necessary header files
#include <iostream>
#include <string>
#include "mage.h"

using namespace std;

//Constructor
Mage::Mage(string name, string race, int level, int health, int mana)
{
    SetName(name);
    SetRace(race);
    SetLevel(level);
    SetHealth(health);
    this->mana = mana;
}

//Setter
void Mage::setMana(int mana_)
{
    mana = mana_;
}

//Getter
int Mage::getMana() const
{
    return mana;
}

//Other functions
int Mage::AddSpell(string spell_name, int spell_damage, int mana_cost)
{
    if(numOfSpells >= 10)
    {
        cout << "Spell limits reached!" << endl;
        return 0;
    }

    spells[numOfSpells].name = spell_name;
    spells[numOfSpells].damage = spell_damage;
    spells[numOfSpells].mana_cost = mana_cost;
    numOfSpells++;

    return numOfSpells;
}

void Mage::nextSpell()
{
    if(active_Spell == numOfSpells)
    {
        active_Spell = 0;
    }
    else
    {
        active_Spell++;
    }
}

void Mage::Attack(Character *target)
{
    if(numOfSpells == 0)
    {
        cout << "This mage has no spells!" << endl;
        return;
    }

    if(mana < spells[active_Spell].mana_cost)
    {
        cout << "Insufficient mana points!" << endl;
    }

    if(active_Spell == numOfSpells)
    {
        nextSpell();
    }

    cout << getName() << " attacked " << target->getName() << " with spell: " << spells[active_Spell].name << ", dealing " << spells[active_Spell].damage << " damage." << endl;
    nextSpell();
    
    mana -= spells[active_Spell].mana_cost;
    int hp = target->getHealth() - spells[active_Spell].damage;
    target->SetHealth(hp);
}

void Mage::Print()
{
    cout << "Character Status:" << endl;
    cout << "Name: " << getName() << endl;
    cout << "Race: " << getRace() << endl;
    cout << "Level: " << getLevel() << endl;
    cout << "Health: " << getHealth() << endl;
    cout << "Spells: " << endl;
    for(int i = 0; i < numOfSpells; i++)
    {
        cout << spells[i].name << endl;
    }
    cout << "---" << endl;
}