#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <utility>

struct Item
{
    std::string name;
    int price;

    Item(std::string itemName, int itemPrice)
        : name(std::move(itemName)), price(itemPrice)
    {
    }
};

int main()
{
    std::map<int, std::shared_ptr<Item>> items;
    auto potion = std::make_shared<Item>("Potion", 50);
    items.insert({1001, potion});

    items.erase(1001);
    std::cout << potion->name << '\n';
}
