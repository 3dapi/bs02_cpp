#include <iostream>
#include <string>
#include <utility>
#include <vector>

struct Item
{
    int id;
    std::string name;
    int count;

    Item(int itemId, std::string itemName, int itemCount)
        : id(itemId),
          name(std::move(itemName)),
          count(itemCount)
    {
    }
};

int main()
{
    std::vector<Item> items;
    items.reserve(2);

    Item& item = items.emplace_back(3, "Elixir", 1);
    std::cout << item.name << '\n';
}
