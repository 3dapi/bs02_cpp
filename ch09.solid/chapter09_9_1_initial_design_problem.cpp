#include <cstdlib>
#include <iostream>

class Monster
{
public:
    int hp = 100;
};

class Player
{
public:
    enum class WeaponType
    {
        Sword,
        Bow,
        Staff
    };

    void Attack(Monster& target)
    {
        int damage = 0;

        switch (weaponType)
        {
        case WeaponType::Sword:
            damage = strength * 2;
            break;

        case WeaponType::Bow:
            damage = dexterity + 5;
            break;

        case WeaponType::Staff:
            damage = intelligence * 2 + 8;
            break;
        }

        const bool critical = std::rand() % 100 < 20;

        if (critical)
        {
            damage *= 2;
        }

        target.hp -= damage;

        if (target.hp < 0)
        {
            target.hp = 0;
        }

        std::cout << "damage=" << damage
                  << " targetHp=" << target.hp
                  << '\n';
    }

private:
    WeaponType weaponType = WeaponType::Sword;
    int strength = 12;
    int dexterity = 10;
    int intelligence = 8;
};

int main()
{
    Player player;
    Monster monster;

    player.Attack(monster);
}
