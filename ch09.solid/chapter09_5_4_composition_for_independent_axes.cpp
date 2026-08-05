#include <iostream>
#include <memory>
#include <utility>

class IAttackBehavior
{
public:
    virtual ~IAttackBehavior() = default;
    virtual int CalculateDamage() const = 0;
};

class IDefenseBehavior
{
public:
    virtual ~IDefenseBehavior() = default;
    virtual int ReduceDamage(int damage) const = 0;
};

class MeleeAttack : public IAttackBehavior
{
public:
    int CalculateDamage() const override
    {
        return 20;
    }
};

class ShieldDefense : public IDefenseBehavior
{
public:
    int ReduceDamage(int damage) const override
    {
        return damage / 2;
    }
};

class Player
{
public:
    Player(std::unique_ptr<IAttackBehavior> attack,
           std::unique_ptr<IDefenseBehavior> defense)
        : attack(std::move(attack)),
          defense(std::move(defense))
    {
    }

    int Attack() const
    {
        return attack->CalculateDamage();
    }

    int Defend(int damage) const
    {
        return defense->ReduceDamage(damage);
    }

private:
    std::unique_ptr<IAttackBehavior> attack;
    std::unique_ptr<IDefenseBehavior> defense;
};

int main()
{
    Player player(
        std::make_unique<MeleeAttack>(),
        std::make_unique<ShieldDefense>()
    );

    std::cout << player.Attack() << ' '
              << player.Defend(30) << '\n';
}
