#include "FileReadException.h"

FileReadException::FileReadException(string msg)
{
    err_message = msg;
}

string FileReadException::getMessage()
{
    return err_message;
}