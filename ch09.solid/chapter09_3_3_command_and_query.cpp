#include <algorithm>
#include <iostream>
#include <vector>

class Inventory
{
public:
    bool AddItem(int itemId)
    {
        if (Contains(itemId))
        {
            return false;
        }

        items.push_back(itemId);
        return true;
    }

    bool RemoveItem(int itemId)
    {
        auto found = std::find(items.begin(), items.end(), itemId);

        if (found == items.end())
        {
            return false;
        }

        items.erase(found);
        return true;
    }

    bool Contains(int itemId) const
    {
        return std::find(items.begin(), items.end(), itemId)
            != items.end();
    }

    std::size_t GetItemCount() const
    {
        return items.size();
    }

private:
    std::vector<int> items;
};

int main()
{
    Inventory inventory;

    inventory.AddItem(1001);
    inventory.AddItem(1002);
    inventory.RemoveItem(1001);

    std::cout << inventory.GetItemCount() << '\n';
}
