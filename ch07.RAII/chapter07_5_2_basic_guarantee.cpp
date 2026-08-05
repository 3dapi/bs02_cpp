#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

class Inventory
{
public:
    void AddItem(const std::string& item)
    {
        if (item == "Error")
        {
            throw std::runtime_error(
                "아이템 추가 실패"
            );
        }

        items.push_back(item);
    }

    std::size_t ItemCount() const
    {
        return items.size();
    }

private:
    std::vector<std::string> items;
};

void ApplyItems(
    Inventory& inventory,
    const std::vector<std::string>& items
)
{
    for (const std::string& item : items)
    {
        inventory.AddItem(item);
    }
}

int main()
{
    Inventory inventory;

    try
    {
        ApplyItems(
            inventory,
            {"Potion", "Sword", "Error"}
        );
    }
    catch (const std::exception& error)
    {
        std::cerr << error.what() << '\n';
    }

    std::cout << inventory.ItemCount() << '\n';
}
