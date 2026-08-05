#include <iostream>
#include <sstream>
#include <string>

int main()
{
    std::istringstream input{"Dark Knight\n"};
    std::string name;

    std::getline(input, name);
    std::cout << name << '\n';
}
