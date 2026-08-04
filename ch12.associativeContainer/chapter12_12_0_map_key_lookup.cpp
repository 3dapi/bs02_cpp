#include <iostream>
#include <map>
#include <string>

int main()
{
    std::map<int, std::string> itemNames
    {
        {1001, "Potion"},
        {1002, "Ether"},
        {1003, "Elixir"}
    };

    std::string name = itemNames.at(1002);
    std::cout << name << '\n';
}
