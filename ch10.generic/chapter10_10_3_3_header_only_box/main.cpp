#include <iostream>
#include <string>

#include "Box.h"

int main()
{
    Box<int> number(10);
    Box<std::string> name("Knight");

    std::cout << number.GetValue() << '\n';
    std::cout << name.GetValue() << '\n';
}
