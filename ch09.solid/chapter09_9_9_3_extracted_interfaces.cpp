#include <iostream>
#include <string_view>

class IRandomSource
{
public:
    virtual ~IRandomSource() = default;
    virtual int NextInt(int min, int max) = 0;
};

class ICombatLog
{
public:
    virtual ~ICombatLog() = default;
    virtual void Write(std::string_view message) = 0;
};

struct AttackRoll
{
    int damage;
    bool critical;
    std::string_view attackName;
};

class IAttackBehavior
{
public:
    virtual ~IAttackBehavior() = default;
    virtual AttackRoll Roll(IRandomSource& randomSource) const = 0;
};

int main()
{
    AttackRoll roll{20, false, "MeleeAttack"};

    std::cout << roll.damage << ' '
              << std::boolalpha << roll.critical << ' '
              << roll.attackName << '\n';
}
