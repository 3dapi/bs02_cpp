#include <iostream>

class Inventory
{
public:
    bool AddItem(int itemId)
    {
        if (itemCount >= 100)
        {
            return false;
        }

        itemIds[itemCount] = itemId;
        ++itemCount;

        return true;
    }

    bool RemoveItem(int itemId)
    {
        for (int i = 0; i < itemCount; ++i)
        {
            if (itemIds[i] == itemId)
            {
                itemIds[i] = itemIds[itemCount - 1];
                --itemCount;
                return true;
            }
        }

        return false;
    }

    int GetItemCount() const
    {
        return itemCount;
    }

private:
    int itemIds[100];
    int itemCount = 0;
};

int main()
{
    Inventory inventory;

    inventory.AddItem(1001);
    inventory.AddItem(1002);
    inventory.RemoveItem(1001);

    std::cout << inventory.GetItemCount() << '\n';
}
