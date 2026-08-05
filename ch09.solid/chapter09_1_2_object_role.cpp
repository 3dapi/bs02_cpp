#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>

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
        if (damage <= 0 || IsDead())
        {
            return 0;
        }

        const int oldHp = hp;
        hp = std::max(hp - damage, 0);
        return oldHp - hp;
    }

    bool IsDead() const
    {
        return hp == 0;
    }

    int GetHp() const
    {
        return hp;
    }

private:
    int hp;
    int maxHp;
};

class IDamageable
{
public:
    virtual ~IDamageable() = default;

    virtual int TakeDamage(int damage) = 0;
    virtual bool IsDead() const = 0;
    virtual std::string_view GetName() const = 0;
};

class Character : public IDamageable
{
public:
    Character(std::string name, int maxHp)
        : name(std::move(name)), health(maxHp)
    {
    }

    int TakeDamage(int damage) override
    {
        return health.TakeDamage(damage);
    }

    bool IsDead() const override
    {
        return health.IsDead();
    }

    std::string_view GetName() const override
    {
        return name;
    }

    int GetHp() const
    {
        return health.GetHp();
    }

private:
    std::string name;
    HealthComponent health;
};

void ApplyExplosionDamage(IDamageable& target, int damage)
{
    target.TakeDamage(damage);
}

int main()
{
    Character character("Knight", 100);

    ApplyExplosionDamage(character, 25);

    std::cout << character.GetName() << ' '
              << character.GetHp() << '\n';
}
