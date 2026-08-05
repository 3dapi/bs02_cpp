#include <iostream>
#include <string>
#include <utility>
#include <vector>

struct Item
{
    int id;
    std::string name;
    int count;

    explicit Item(int itemId, std::string itemName, int itemCount)
        : id(itemId),
          name(std::move(itemName)),
          count(itemCount)
    {
    }
};

int main()
{
    std::vector<Item> items;

    items.push_back(Item{1, "Potion", 10});
    items.emplace_back(2, "Ether", 5);

    std::cout << items.size() << '\n';
}
