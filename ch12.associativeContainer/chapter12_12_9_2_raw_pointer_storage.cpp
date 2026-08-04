#include <iostream>
#include <map>
#include <string>

struct Item
{
    std::string name;
    int price;
};

int main()
{
    std::map<int, Item*> items;
    Item potion{"Potion", 50};
    items.insert({1001, &potion});

    std::cout << items.at(1001)->name << '\n';
    items.erase(1001);
    std::cout << potion.name << '\n';
}
