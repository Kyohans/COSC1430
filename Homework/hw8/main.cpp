#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "TreasureMap.h"
#include "FileReadException.h"
#include "Location.h"

using namespace std;

//overload operator << of Location class, no changes needed
ostream& operator<<(ostream& os, Location& pt) {
	return os << pt.getName();
}

//overload operator >> of Location class, no changes needed
istream& operator >> (istream& os, Location& pt) {
	string name;
	float x,y;
	os >> name >> x >> y;
	pt.setName(name);
	pt.setX(x);
	pt.setY(y);
	
	return os;
}


//FIX ME: Implement readmap function that reads from a file and return a proper TreasureMap object
template <typename T>
TreasureMap<T> readMap(string readIn, int max)
{
    ifstream file;
    try
    {
        file.open(readIn);
        if(file.fail())
        {
            FileReadException err("File not found!");
            throw err;
        }
    }
    catch(FileReadException &err)
    {
        cout << err.getMessage() << endl;
        exit(0);
    }

    TreasureMap<T> Map(max);
    T step;
    int lines = 0;
    while(!file.eof())
    {
        try
        {
            file >> step;
            lines++;

            if(Map.getTotalSteps() < lines)
            {
                ostringstream msg;
                msg << "Error reading map: " << readIn << " contains more than " << max << " steps!";
                FileReadException err(msg.str());
                throw err;
            }

            Map.addStep(step);
        }
        catch(FileReadException &err)
        {
            cout << err.getMessage() << endl;
            exit(0);
        }
    }

    return Map;
}


int main()
{
    string file_name, file_type;
    FileReadException err("File type is not valid!");
    int max_steps;
    cin >> file_name >> file_type >> max_steps;
    
    
    try{
        if (file_type == "string"){
            TreasureMap<string> Tmap = readMap<string>(file_name, max_steps);
            for (int i = 0; i < Tmap.getTotalSteps()-1; i ++){
                Tmap.nextStep();
            }

        } else if (file_type == "int"){
            //FIX ME: Create a TreasureMap of type int, call readMap to read the file_name and file_type
            //Then use a for loop to call the map.nextStep()
            TreasureMap<int> Imap = readMap<int>(file_name, max_steps);
            for(int i = 0; i < Imap.getTotalSteps()-1; i++)
                Imap.nextStep();

        } else if (file_type == "char"){
            //FIX ME: Create a TreasureMap of type char, call readMap to read the file_name and file_type
            //Then use a for loop to call the map.nextStep()
            TreasureMap<char> Cmap = readMap<char>(file_name, max_steps);
            for(int i = 0; i < Cmap.getTotalSteps()-1; i++)
                Cmap.nextStep();

        } else if (file_type == "location"){
            //FIX ME: Create a TreasureMap of type Location, call readMap to read the file_name and file_type
            //Then use a for loop to call the map.nextStep()
            TreasureMap<Location> Lmap = readMap<Location>(file_name, max_steps);
            for(int i = 0; i < Lmap.getTotalSteps()-1; i++)
                Lmap.nextStep();
            
        }
        else{
            throw err;
        }
    }catch(FileReadException &err){
        //FIX ME: prints out the exception message using getMessage() here
        cout << err.getMessage() << endl;
    }
    return 0;
}
