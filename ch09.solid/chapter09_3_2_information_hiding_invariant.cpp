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
        hp = std::clamp(hp - damage, 0, maxHp);
        return oldHp - hp;
    }

    int Recover(int amount)
    {
        if (amount <= 0)
        {
            return 0;
        }

        const int oldHp = hp;
        hp = std::clamp(hp + amount, 0, maxHp);
        return hp - oldHp;
    }

    int GetHp() const
    {
        return hp;
    }

private:
    int hp;
    int maxHp;
};

int main()
{
    HealthComponent health(100);
    health.TakeDamage(150);
    health.Recover(20);

    std::cout << health.GetHp() << '\n';
}
