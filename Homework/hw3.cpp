#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

struct kitten{
    string name;
    string color;
    int score;
};

struct roster{
    kitten kittens[11]; // Size of 11 instead of 10 to avoid error when removing last element of roster
    int size = 0;
};

/* METHOD DECLARATIONS */
void printMenu();
void printRoster(roster k);
void findKitten(string name, roster k);
void addKitten(kitten newKitten, roster &k);
void deleteKitten(string name, roster &k);
void updateKitten(string name, roster &k);
void printToFile(string fileName, roster k);
void getKittenFromFile(string fileName, roster &k);

int main()
{
    roster kittenRoster;
    ifstream file;
    string fileName;

    cout << "Please enter filename: \n> ";
    cin >> fileName;

    file.open(fileName);
    if(file.fail())
    {
        cout << "ERROR: File not found! Exiting program..." << endl;
        return 0;
    }
    cout << "File found!\n" << endl;

    while(!file.eof())
    {
        file >> kittenRoster.kittens[kittenRoster.size].name;
        file >> kittenRoster.kittens[kittenRoster.size].color;
        file >> kittenRoster.kittens[kittenRoster.size].score;

        if(kittenRoster.size != 10)
        {
            kittenRoster.size++;
        }
    }
    file.close();

    char input;
    string userString;
    do{
        printMenu();
        cin >> input;

        switch(input)
        {
            case 'a':   // Add new kitten
            {
                if(kittenRoster.size != 10)
                {
                    kitten newKitten;
                    addKitten(newKitten, kittenRoster);
                }
                else
                {
                    cout << "\nImpossible! The roster is already full" << endl;
                }
                break;
            }
            case 'd':   // Delete kitten
            {
                if(kittenRoster.size == 0)
                {
                    cout << "Impossible! The roster is empty\n" << endl;
                    break;
                }
                cout << "Enter kitten's name: \n> ";
                cin >> userString;
                
                deleteKitten(userString, kittenRoster);
                break;
            }
            case 'u':   // Update kitten color and cuteness score
            {
                cout << "Enter kitten's name: \n> ";
                cin >> userString;

                updateKitten(userString, kittenRoster);
                break;
            }
            case 'f':   // Find kitten
            {
                cout << "\nEnter kitten's name \n> ";
                cin >> userString;
                findKitten(userString, kittenRoster);
                break;
            }
            case 'l':   // Load kitten info from file
            {
                cout << "Enter filename: \n> ";
                cin >> fileName;

                getKittenFromFile(fileName, kittenRoster);
                break;
            }
            case 's':   // Save kitten info from file (truncates file before printing)
            {
                cout << "Enter filename: \n> ";
                cin >> fileName;

                printToFile(fileName, kittenRoster);
                break;
            }
            case 'o':   // Output roster to console
            {
                printRoster(kittenRoster);
                break;
            }
            case 'q':   // Quit (Added to avoid default case)
            {
                break;
            }
            default:
            {
                cout << "\nERROR: Please enter a valid option!" << endl;
                break;
            }
            
        }
    } while(input != 'q');


}

void printMenu()
{
    cout << "MENU" << endl;
    cout << "a - Add kitten \nd - Delete kitten \nu - Update kitten color and cuteness score \nf - Find kitten" << endl;
    cout << "l - Load kitten info from file \ns - Save kitten info to file \no - Output roster \nq - Quit" << endl;
    cout << endl << "Choose an option: \n> ";
}

void printRoster(roster k)
{
    cout << "\nROSTER: " << k.size << endl;
    for (int i = 0; i < k.size; i++)
    {
        cout << "Kitten " << i + 1 << " -- Name: " << k.kittens[i].name << ", Color: " << k.kittens[i].color << ", Score: " << k.kittens[i].score << endl;
    }
    cout << endl;
}

void findKitten(string name, roster k)
{
    for(int i = 0; i < k.size; i++)
    {
        if(name == k.kittens[i].name)
        {
            cout << k.kittens[i].name << " info: " << k.kittens[i].color << ", " << k.kittens[i].score << "\n" << endl;
            return;
        }
    }
    cout << "Kitten " << name << " not found.\n" << endl;
}

void addKitten(kitten newKitten, roster &k)
{
        cout << "Enter new kitten's name: \n> ";
        cin >> newKitten.name;
        k.kittens[k.size].name = newKitten.name;

        cout << "\nEnter new kitten's color: \n> ";
        cin >> newKitten.color;
        k.kittens[k.size].color = newKitten.color;

        cout << "\nEnter new kitten's cuteness score: \n> ";
        cin >> newKitten.score;
        k.kittens[k.size].score = newKitten.score;

        cout << newKitten.name << " has been added to the roster!\n" << endl;
        k.size++;
}

void deleteKitten(string name, roster &k)
{
    bool catFound = false;
    int pos;

    for (int i = 0; i < k.size; i++)
    {
        if (k.kittens[i].name == name)
        {
            catFound = true;
            pos = i;
            break;
        }
    }

    if(!catFound)
    {
        cout << "Kitten " << name << " not found!\n" << endl;
        return;
    }
    else
    {
        for (int i = pos; i < k.size; i++)
        {

            k.kittens[i].name = k.kittens[i + 1].name;
            k.kittens[i].color = k.kittens[i + 1].color;
            k.kittens[i].score = k.kittens[i + 1].score;
        }
    }
    k.size--;
    cout << "Kitten " << name << " deleted from roster\n" << endl;
}

void updateKitten(string name, roster &k)
{
    bool catFound = false;
    int pos;
    for(int i = 0; i < k.size; i++)
    {
        if(name == k.kittens[i].name)
        {
            catFound = true;
            pos = i;
            i = k.size;
        }
    }

    if(!catFound)
    {
        cout << "Kitten not found!\n" << endl;
        return;
    }

    cout << "\nEnter " << name << "'s new color: \n> ";
    cin >> k.kittens[pos].color;

    cout << "And new score: \n> ";
    cin >> k.kittens[pos].score;

    cout << name << "'s color and score has been updated!\n" << endl;

}

void getKittenFromFile(string fileName, roster &k)
{
    ifstream file;
    file.open(fileName);
    if (file.fail())
    {
        cout << fileName << " not found!\n" << endl;
        return;
    }

    if(k.size == 19)
    {
        cout << "ERROR: Roster is full!" << endl;
    }
    else
    {
        while(!file.eof())
        {
            if(k.size == 10)
            {
                cout << "ERROR: Reached end of roster; can no longer continue!" << endl;
                file.close();
                return;
            }
            else
            {
                file >> k.kittens[k.size].name;
                file >> k.kittens[k.size].color;
                file >> k.kittens[k.size].score;
            }
            k.size++;
        }
    }
    cout << "Successfully loaded " << fileName << " into roster!" << endl;
    file.close();
}

void printToFile(string fileName, roster k)
{
    ofstream file;
    file.open(fileName, fstream::trunc);

    file << "ROSTER: " << k.size << endl;
    for(int i = 0; i < k.size; i++)
    {
        file << "Kitten " << i + 1 << " -- Name: " << k.kittens[i].name << ", Color: " << k.kittens[i].color << ", Score: " << k.kittens[i].score << endl;
    }
    cout << "Roster printed to " << fileName << endl;
    file.close();
}
