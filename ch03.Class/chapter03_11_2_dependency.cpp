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
        hp -= damage;
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
    void Attack(Weapon& weapon, Enemy& enemy);
};

void Player::Attack(Weapon& weapon, Enemy& enemy)
{
    int power = weapon.GetPower();

    enemy.TakeDamage(power);
}

int main()
{
    Player player;
    Weapon weapon;
    Enemy enemy;

    player.Attack(weapon, enemy);

    std::cout << enemy.GetHp() << '\n';
}
