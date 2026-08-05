#include <iostream>

class Weapon
{
public:
    int GetPower() const
    {
        return power;
    }

private:
    int power = 20;
};

class Enemy
{
public:
    void TakeDamage(int damage)
    {
        if (damage <= 0)
        {
            return;
        }

        hp -= damage;

        if (hp < 0)
        {
            hp = 0;
        }
    }

    int GetHp() const
    {
        return hp;
    }

private:
    int hp = 100;
};

class Player
{
public:
    void EquipWeapon(Weapon* newWeapon)
    {
        weapon = newWeapon;
    }

    void Attack(Enemy& enemy)
    {
        if (weapon == nullptr)
        {
            return;
        }

        int power = weapon->GetPower();

        enemy.TakeDamage(power);
    }

private:
    Weapon* weapon = nullptr;
};

int main()
{
    Player player;
    Weapon weapon;
    Enemy enemy;

    player.EquipWeapon(&weapon);
    player.Attack(enemy);

    std::cout << enemy.GetHp() << '\n';
}
