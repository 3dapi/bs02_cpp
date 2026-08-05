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
          count(itemCount < 0 ? 0 : itemCount)
    {
    }
};

int main()
{
    std::vector<Item> items;
    items.push_back({1, "Potion", -10});
    items.push_back(Item{2, "Ether", 5});

    std::cout << items[0].count << ' '
              << items[1].count << '\n';
}
