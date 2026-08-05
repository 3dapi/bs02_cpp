#include <iostream>
#include <vector>

class Inventory
{
public:
    void AddItem(int itemId)
    {
        items.push_back(itemId);
    }

    std::size_t Count() const
    {
        return items.size();
    }

private:
    std::vector<int> items;
};

class Weapon
{
public:
    void Attack() const
    {
        std::cout << "Weapon attack\n";
    }
};

class Player
{
public:
    void AddItem(int itemId)
    {
        inventory.AddItem(itemId);
    }

    void Attack() const
    {
        weapon.Attack();
    }

    std::size_t ItemCount() const
    {
        return inventory.Count();
    }

private:
    Inventory inventory;
    Weapon weapon;
};

int main()
{
    Player player;
    player.AddItem(101);
    player.Attack();
    std::cout << player.ItemCount() << '\n';
}
