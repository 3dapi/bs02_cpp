#include <iostream>
#include <optional>
#include <string>
#include <vector>

struct Item
{
    int id;
    std::string name;
};

class Inventory
{
public:
    void Add(Item item)
    {
        items.push_back(std::move(item));
    }

    std::optional<Item> FindById(int id) const
    {
        for (const Item& item : items)
        {
            if (item.id == id)
            {
                return item;
            }
        }

        return std::nullopt;
    }

private:
    std::vector<Item> items;
};

int main()
{
    Inventory inventory;
    inventory.Add(Item{1001, "Potion"});

    if (std::optional<Item> item = inventory.FindById(1001))
    {
        std::cout << item->name << '\n';
    }
}
