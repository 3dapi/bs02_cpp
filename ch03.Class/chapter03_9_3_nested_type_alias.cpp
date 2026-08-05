#include <iostream>

class Inventory
{
public:
    using ItemId = int;
    using ItemCount = int;

    bool AddItem(ItemId id, ItemCount count)
    {
        if (count <= 0)
        {
            return false;
        }

        lastItemId = id;
        totalItemCount += count;

        return true;
    }

    ItemCount GetTotalItemCount() const
    {
        return totalItemCount;
    }

private:
    ItemId lastItemId = 0;
    ItemCount totalItemCount = 0;
};

int main()
{
    Inventory::ItemId swordId = 1001;
    Inventory::ItemCount swordCount = 5;
    Inventory inventory;

    inventory.AddItem(swordId, swordCount);

    std::cout << inventory.GetTotalItemCount() << '\n';
}
