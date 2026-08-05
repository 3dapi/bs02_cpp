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
    std::map<int, Item> items;
    items.insert({1001, Item{"Potion", 50}});
    items.insert({1002, Item{"Ether", 80}});

    std::cout << items.at(1001).name << '\n';
    items.erase(1001);
    std::cout << items.size() << '\n';
}
