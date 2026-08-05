#include <iostream>

class HealthComponent
{
public:
    explicit HealthComponent(int maxHp)
        : hp(maxHp), maxHp(maxHp)
    {
    }

    void TakeDamage(int damage)
    {
        if (damage > 0)
        {
            hp -= damage;

            if (hp < 0)
            {
                hp = 0;
            }
        }
    }

    int GetHp() const
    {
        return hp;
    }

private:
    int hp;
    int maxHp;
};

class Character
{
public:
    explicit Character(int hp)
        : health(hp)
    {
    }

    void TakeDamage(int damage)
    {
        health.TakeDamage(damage);
    }

    int GetHp() const
    {
        return health.GetHp();
    }

private:
    HealthComponent health;
};

int main()
{
    Character character(100);
    character.TakeDamage(30);
    std::cout << character.GetHp() << '\n';
}
