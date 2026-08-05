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
        // std::move를 사용, std::string 복사 방지.
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
    inventory.Add(Item{2001, "Iron Sword"});
    inventory.Add(Item{3001, "Wooden Shield"});
    inventory.Add(Item{4001, "Health Potion"});
    inventory.Add(Item{5001, "Bronze armor"});

    if (auto item = inventory.FindById(2001))
    {
        std::cout << item->name << '\n';
    }
}
