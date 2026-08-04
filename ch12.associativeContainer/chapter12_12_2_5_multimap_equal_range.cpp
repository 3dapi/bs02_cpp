#include <iostream>
#include <map>
#include <string>

int main()
{
    std::multimap<std::string, std::string> items
    {
        {"Potion", "Small Potion"},
        {"Potion", "Large Potion"},
        {"Weapon", "Sword"}
    };

    auto [first, last] = items.equal_range("Potion");

    for (auto iterator = first; iterator != last; ++iterator)
    {
        std::cout << iterator->second << '\n';
    }
}
