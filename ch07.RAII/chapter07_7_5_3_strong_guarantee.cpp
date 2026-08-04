#include <iostream>
#include <string>
#include <vector>

class Inventory
{
public:
    void ReplaceItems(
        const std::vector<std::string>& newItems
    )
    {
        std::vector<std::string> copy = newItems;

        items.swap(copy);
    }

    void Print() const
    {
        for (const std::string& item : items)
        {
            std::cout << item << ' ';
        }

        std::cout << '\n';
    }

private:
    std::vector<std::string> items;
};

int main()
{
    Inventory inventory;

    inventory.ReplaceItems({"Potion", "Sword"});
    inventory.Print();
}
