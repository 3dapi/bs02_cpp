#include <iostream>
#include <limits>
#include <sstream>
#include <string>

int main()
{
    std::istringstream input{"20\nDark Knight\n"};

    int age = 0;
    std::string name;

    input >> age;
    input.ignore(
        std::numeric_limits<std::streamsize>::max(),
        '\n');
    std::getline(input, name);

    std::cout << age << ' ' << name << '\n';
}
