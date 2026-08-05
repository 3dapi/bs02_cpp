#include <iostream>
#include <string>
#include <unordered_map>

int main()
{
    std::unordered_multimap<std::string, std::string> categoryItems;

    categoryItems.emplace("Potion", "Small Potion");
    categoryItems.emplace("Potion", "Large Potion");

    auto [first, last] = categoryItems.equal_range("Potion");

    for (auto iterator = first; iterator != last; ++iterator)
    {
        std::cout << iterator->second << '\n';
    }
}
