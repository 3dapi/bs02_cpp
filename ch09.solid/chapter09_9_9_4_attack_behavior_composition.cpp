#include <algorithm>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>

class IRandomSource
{
public:
    virtual ~IRandomSource() = default;
    virtual int NextInt(int min, int max) = 0;
};

class FixedRandomSource : public IRandomSource
{
public:
    explicit FixedRandomSource(int value)
        : value(value)
    {
    }

    int NextInt(int min, int max) override
    {
        return std::clamp(value, min, max);
    }

private:
    int value;
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

class MeleeAttack : public IAttackBehavior
{
public:
    explicit MeleeAttack(int damage)
        : damage(damage)
    {
    }

    AttackRoll Roll(IRandomSource& randomSource) const override
    {
        const bool critical = randomSource.NextInt(1, 100) <= 20;

        return AttackRoll
        {
            critical ? damage * 2 : damage,
            critical,
            "MeleeAttack"
        };
    }

private:
    int damage;
};

class Character
{
public:
    Character(std::string name,
              std::unique_ptr<IAttackBehavior> attackBehavior)
        : name(std::move(name)),
          attackBehavior(std::move(attackBehavior))
    {
        if (this->attackBehavior == nullptr)
        {
            throw std::invalid_argument(
                "attackBehavior is null");
        }
    }

    AttackRoll RollAttack(IRandomSource& randomSource) const
    {
        return attackBehavior->Roll(randomSource);
    }

    std::string_view GetName() const
    {
        return name;
    }

private:
    std::string name;
    std::unique_ptr<IAttackBehavior> attackBehavior;
};

int main()
{
    FixedRandomSource randomSource(10);
    Character character(
        "Knight",
        std::make_unique<MeleeAttack>(20)
    );

    const AttackRoll roll = character.RollAttack(randomSource);

    std::cout << character.GetName() << ' '
              << roll.damage << '\n';
}
