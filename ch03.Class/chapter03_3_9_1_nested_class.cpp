#include <iostream>

class Inventory
{
public:
    class Item
    {
    public:
        void Set(int itemId, int itemCount)
        {
            id = itemId;
            count = itemCount;
        }

        int GetId() const
        {
            return id;
        }

        int GetCount() const
        {
            return count;
        }

    private:
        int id = 0, count = 0;
    };

private:
    Item items[100];
    int itemCount = 0;
};

int main()
{
    Inventory::Item item;

    item.Set(1001, 5);

    std::cout << item.GetId() << ", "
              << item.GetCount() << '\n';
}
