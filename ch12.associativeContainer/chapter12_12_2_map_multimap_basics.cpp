#include <iostream>
#include <map>
#include <string>

int main()
{
    std::map<int, std::string> itemNames
    {
        {1001, "Potion"},
        {1002, "Ether"}
    };

    std::multimap<std::string, std::string> categoryItems
    {
        {"Potion", "Small Potion"},
        {"Potion", "Large Potion"},
        {"Weapon", "Sword"}
    };

    std::cout << itemNames.at(1001) << '\n';
    std::cout << categoryItems.count("Potion") << '\n';
}
