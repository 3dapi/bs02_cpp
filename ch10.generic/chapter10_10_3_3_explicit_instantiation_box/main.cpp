#include <iostream>
#include <string>

#include "Box.h"

int main()
{
    Box<int> number(10);
    Box<double> real(3.5);
    Box<std::string> name("Knight");

    std::cout << number.GetValue() << '\n';
    std::cout << real.GetValue() << '\n';
    std::cout << name.GetValue() << '\n';
}
