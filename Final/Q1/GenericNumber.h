#ifndef GENERICNUMBER_H
#define GENERICNUMBER_H

#include <iostream>
#include <string>

class GenericNumber
{
private:
    std::string value;
    std::string type;
    bool isInteger(const std::string & buffer) const;
    bool isDouble(const std::string & buffer) const;
public:
    void read(const std::string &_type);
    void print() const;
};

#endif
