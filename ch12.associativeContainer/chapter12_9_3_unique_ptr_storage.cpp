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
    std::map<int, std::unique_ptr<Item>> items;

    items.try_emplace(
        1001,
        std::make_unique<Item>("Potion", 50));

    auto item = std::make_unique<Item>("Elixir", 100);
    auto [position, inserted] =
        items.try_emplace(1001, std::move(item));

    std::cout << position->second->name << '\n';
    std::cout << std::boolalpha << inserted << ' '
              << (item != nullptr) << '\n';
}
