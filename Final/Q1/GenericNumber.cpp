#include "GenericNumber.h"
#include <iostream>

using namespace std;

bool GenericNumber::isInteger(const string & buffer) const
{
    for(unsigned int i=0;i<buffer.length();i++)
        if (isdigit(buffer[i]) == false)
            return false;
    return true;
}

bool GenericNumber::isDouble(const string & buffer) const
{
    bool dotSymbol = false;
    for(unsigned int i=0;i<buffer.length();i++)
        if (isdigit(buffer[i]) == false)
        {
            if (dotSymbol == false && i > 0)
                dotSymbol = true;
            else
                return false;
        }
    return true;
}

//Write the read method here
void GenericNumber::read(const string &_type)
{
    bool done = false;
    if(_type == "integer" || _type == "int")
    {
        while(!done)
        {
            try
            {
                string _value;
                cin >> _value;
                if(!isInteger(_value))
                {
                    throw runtime_error("The input is not an integer value. Enter a new value: ");
                }
                this->type = _type;
                this->value = _value;
                done = true;
            }
            catch(runtime_error& excpt)
            {
                cout << excpt.what();
            }
        }
    }
    else if(_type == "double")
    {
        while(!done)
        {
            try
            {
                string _value;
                cin >> _value;
                if(!isDouble(_value))
                {
                    throw runtime_error("The input is not a double value. Enter a new value: ");
                }
                this->type = _type;
                this->value = _value;
                done = true;
            }
            catch(runtime_error& excpt)
            {
                cout << excpt.what();
            }
        }
    }
}

void GenericNumber::print() const
{
    cout << "The value " << value << " is a(n) " << type << endl;
}
