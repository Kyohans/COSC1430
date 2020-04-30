#include "GenericNumber.h"

int main()
{
    std::string type;
    std::cin >> type;
    GenericNumber num1;
    num1.read(type);
    num1.print();
    return 0;
}