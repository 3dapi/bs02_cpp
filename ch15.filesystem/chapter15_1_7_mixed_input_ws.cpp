#include <iostream>
#include <sstream>
#include <string>

int main()
{
    std::istringstream input{"20\n   Dark Knight\n"};

    int age = 0;
    std::string name;

    input >> age;
    std::getline(input >> std::ws, name);

    std::cout << age << ' ' << name << '\n';
}
