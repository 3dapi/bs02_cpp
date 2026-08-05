#include <iostream>
#include <string>

#include "Box.h"

int main()
{
    Box<std::string> box("Knight");
    std::cout << box.GetValue() << '\n';
}
