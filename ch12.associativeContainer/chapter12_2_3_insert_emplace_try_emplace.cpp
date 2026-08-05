#include <iostream>
#include <map>
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
    std::map<int, Item> items;

    auto [first, firstInserted] =
        items.insert({1001, Item{"Potion", 50}});
    auto [second, secondInserted] =
        items.emplace(1002, Item{"Ether", 80});
    auto [third, thirdInserted] =
        items.try_emplace(1001, "Elixir", 100);

    std::cout << first->second.name << ' ' << firstInserted << '\n';
    std::cout << second->second.name << ' ' << secondInserted << '\n';
    std::cout << third->second.name << ' ' << thirdInserted << '\n';
}
