#include <iostream>
#include <map>
#include <string>

int main()
{
    std::map<int, std::string> items
    {
        {1001, "Potion"},
        {1002, "Ether"}
    };

    auto iterator = items.find(1001);
    std::string& name = iterator->second;

    items.insert({1003, "Elixir"});

    std::cout << iterator->second << '\n';
    std::cout << name << '\n';
}
