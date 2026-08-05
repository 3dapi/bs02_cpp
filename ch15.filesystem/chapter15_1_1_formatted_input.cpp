#include <iostream>
#include <sstream>
#include <string>

int main()
{
    std::istringstream input{"Knight 20"};

    std::string name;
    int level = 0;

    if (input >> name >> level)
    {
        std::cout << name << ' ' << level << '\n';
    }
}
