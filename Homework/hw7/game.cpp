#include <iostream>
#include "game.h"
#include <string>
#include "character.h"

using namespace std;

Game::Game()
{
    num_of_characters = 0;
    current_turn = 1;

    for (int i = 0; i <= 1; i++)
        players[i] = nullptr;
}

void Game::RemoveCharacter(int index)
{
    if (index < 0 || index > 1)
    {
        cout << "Invalid index!" << endl;
        return;
    }

    Character *temp[2];
    if(index == 0) {
        temp[0] = players[1];
        temp[1] = nullptr;
    } else {
        temp[0] = players[0];
        temp[1] = nullptr;
    }

    if (players[index] != nullptr)
    {
        cout << players[index]->getName() << " has been removed from the game." << endl;
        for(int i = 0; i < num_of_characters; i++)
        {
            players[i] = nullptr;
        }
    }
    else
    {
        cout << "Character has already been removed" << endl;
    }

    players[0] = temp[0];
    num_of_characters--;
}

void Game::AddCharacter(Character *c)
{
    if (num_of_characters == 2)
    {
        cout << "Character limit reached, please wait for the next game!" << endl;
        return;
    }
    else
    {
        players[num_of_characters] = c;
    }
    num_of_characters++;
}

void Game::NextTurn()
{
    for(int i = 0; i < num_of_characters; i++)
    {
        if(players[i]->getHealth() <= 0)
        {
            cout << players[i]->getName() << " has already been eliminated" << endl;
            if(i == 0)
            {
                cout << players[i+1]->getName() << " wins!" << endl;
            } else {
                cout << players[i-1]->getName() << " wins!" << endl;
            }
            return;
        }
    }

    if (num_of_characters != 2)
    {
        cout << "Need more players!" << endl;
    }
    else
    {
        players[0]->Attack(players[1]);
        if (players[1]->getHealth() <= 0)
        {
            cout << players[0]->getName() << " wins!" << endl;
        }

        players[1]->Attack(players[0]);
        if (players[0]->getHealth() <= 0)
        {
            cout << players[1]->getName() << " wins!" << endl;
        }
    }

    current_turn++;
    return;
}

void Game::Print()
{
    for (int i = 0; i < num_of_characters; i++)
    {
        if (players[i] != nullptr)
            players[i]->Print();
    }
}
