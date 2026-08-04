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
            throw std::invalid_argument(
                "maxHp must be positive");
        }
    }

    int TakeDamage(int damage)
    {
        if (damage <= 0 || IsDead())
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

    int GetMaxHp() const
    {
        return maxHp;
    }

    bool IsDead() const
    {
        return hp == 0;
    }

private:
    int hp;
    int maxHp;
};

int main()
{
    HealthComponent health(100);

    std::cout << health.TakeDamage(30) << ' '
              << health.GetHp() << '\n';
}
