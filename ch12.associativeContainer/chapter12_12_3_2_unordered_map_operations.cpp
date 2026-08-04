#include <iostream>
#include <string>
#include <unordered_map>

int main()
{
    std::unordered_map<int, std::string> itemNames
    {
        {1001, "Potion"},
        {1002, "Ether"}
    };

    itemNames[1003] = "Elixir";
    itemNames.try_emplace(1004, "Antidote");
    itemNames.insert_or_assign(1002, "High Ether");

    std::cout << itemNames.at(1002) << '\n';
}
