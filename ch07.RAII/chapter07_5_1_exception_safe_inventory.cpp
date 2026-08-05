#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

class Inventory
{
public:
    void AddItem(const std::string& item)
    {
        items.push_back(item);
    }

    std::size_t ItemCount() const
    {
        return items.size();
    }

private:
    std::vector<std::string> items;
};

int main()
{
    Inventory inventory;

    inventory.AddItem("Potion");
    inventory.AddItem("Sword");

    std::cout << inventory.ItemCount() << '\n';
}
