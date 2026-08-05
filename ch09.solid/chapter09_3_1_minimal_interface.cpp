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
        const int oldHp = hp;
        hp = std::max(hp - std::max(damage, 0), 0);
        return oldHp - hp;
    }

    int Recover(int amount)
    {
        const int oldHp = hp;
        hp = std::min(hp + std::max(amount, 0), maxHp);
        return hp - oldHp;
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
    health.TakeDamage(15);

    std::cout << health.GetHp() << '\n';
}
