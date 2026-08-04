#include <algorithm>
#include <iostream>

class IDamageable
{
public:
    virtual ~IDamageable() = default;
    virtual int TakeDamage(int damage) = 0;
};

class Character : public IDamageable
{
public:
    explicit Character(int hp)
        : hp(hp)
    {
    }

    int TakeDamage(int damage) override
    {
        const int oldHp = hp;
        hp = std::max(hp - std::max(damage, 0), 0);
        return oldHp - hp;
    }

    int GetHp() const
    {
        return hp;
    }

private:
    int hp;
};

class CombatService
{
public:
    explicit CombatService(int attackPower)
        : attackPower(attackPower)
    {
    }

    int Attack(IDamageable& target)
    {
        return target.TakeDamage(attackPower);
    }

private:
    int attackPower;
};

int main()
{
    Character target(100);
    CombatService combatService(30);

    std::cout << combatService.Attack(target) << ' '
              << target.GetHp() << '\n';
}
