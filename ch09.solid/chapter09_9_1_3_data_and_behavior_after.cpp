#include <algorithm>
#include <iostream>
#include <stdexcept>

class HealthComponent
{
public:
    explicit HealthComponent(int maxHp)
        : hp(maxHp), maxHp(maxHp)
    {
        if (maxHp <= 0)
        {
            throw std::invalid_argument("maxHp must be positive");
        }
    }

    int TakeDamage(int damage)
    {
        if (damage <= 0)
        {
            return 0;
        }

        const int oldHp = hp;
        hp = std::max(hp - damage, 0);
        return oldHp - hp;
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
    explicit Character(int maxHp)
        : health(maxHp)
    {
    }

    int TakeDamage(int damage)
    {
        return health.TakeDamage(damage);
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
    Character target(100);
    const int actualDamage = target.TakeDamage(120);

    std::cout << actualDamage << ' '
              << target.GetHp() << '\n';
}
