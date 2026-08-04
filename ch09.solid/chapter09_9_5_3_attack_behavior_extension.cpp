#include <algorithm>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string_view>
#include <utility>

class IAttackBehavior
{
public:
    virtual ~IAttackBehavior() = default;

    virtual int CalculateDamage() const = 0;
    virtual std::string_view GetName() const = 0;
};

class MeleeAttack : public IAttackBehavior
{
public:
    explicit MeleeAttack(int strength)
        : strength(std::max(strength, 0))
    {
    }

    int CalculateDamage() const override
    {
        return strength * 2;
    }

    std::string_view GetName() const override
    {
        return "Melee";
    }

private:
    int strength;
};

class MagicAttack : public IAttackBehavior
{
public:
    MagicAttack(int intelligence, int spellPower)
        : intelligence(std::max(intelligence, 0)),
          spellPower(std::max(spellPower, 0))
    {
    }

    int CalculateDamage() const override
    {
        return intelligence * 2 + spellPower;
    }

    std::string_view GetName() const override
    {
        return "Magic";
    }

private:
    int intelligence;
    int spellPower;
};

class Player
{
public:
    explicit Player(std::unique_ptr<IAttackBehavior> attackBehavior)
        : attackBehavior(std::move(attackBehavior))
    {
        if (this->attackBehavior == nullptr)
        {
            throw std::invalid_argument("attackBehavior is null");
        }
    }

    int CalculateDamage() const
    {
        return attackBehavior->CalculateDamage();
    }

    void ChangeAttack(
        std::unique_ptr<IAttackBehavior> newBehavior)
    {
        if (newBehavior == nullptr)
        {
            throw std::invalid_argument("newBehavior is null");
        }

        attackBehavior = std::move(newBehavior);
    }

private:
    std::unique_ptr<IAttackBehavior> attackBehavior;
};

int main()
{
    Player player(std::make_unique<MeleeAttack>(12));
    std::cout << player.CalculateDamage() << '\n';

    player.ChangeAttack(
        std::make_unique<MagicAttack>(15, 8));

    std::cout << player.CalculateDamage() << '\n';
}
