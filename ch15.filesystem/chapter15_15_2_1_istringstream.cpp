#include <iostream>
#include <sstream>
#include <string>

int main()
{
    std::string text = "1001 Potion 10";
    std::istringstream input{text};

    int id = 0;
    std::string name;
    int count = 0;

    if (input >> id >> name >> count)
    {
        std::cout << id << ' ' << name << ' ' << count << '\n';
    }
}
