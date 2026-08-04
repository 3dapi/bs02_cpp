#include <iostream>
#include <map>
#include <string>
#include <vector>

struct Item
{
    std::string name;
};

int main()
{
    std::map<std::string, std::vector<Item>> itemsByCategory;
    itemsByCategory["Potion"].push_back({"Small Potion"});
    itemsByCategory["Potion"].push_back({"Large Potion"});

    for (const Item& item : itemsByCategory.at("Potion"))
    {
        std::cout << item.name << '\n';
    }
}
