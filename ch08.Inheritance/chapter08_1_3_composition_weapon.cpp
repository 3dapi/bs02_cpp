#include <iostream>

class Weapon
{
public:
    void Attack() const
    {
        std::cout << "Weapon attack\n";
    }
};

class Character
{
public:
    virtual ~Character() = default;
};

class Player : public Character
{
public:
    void Attack() const
    {
        weapon.Attack();
    }

private:
    Weapon weapon;
};

int main()
{
    Player player;
    player.Attack();
}
