#include <string>
#include <exception>

using namespace std;

#pragma once

class FileReadException : public exception
{
    private:
        string err_message;
    public:
        FileReadException(string);
        string getMessage();
};