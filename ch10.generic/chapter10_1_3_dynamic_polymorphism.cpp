#include <iostream>

class IAttackBehavior
{
public:
    virtual ~IAttackBehavior() = default;
    virtual int CalculateDamage() const = 0;
};

class MeleeAttack : public IAttackBehavior
{
public:
    explicit MeleeAttack(int damage)
        : damage(damage)
    {
    }

    int CalculateDamage() const override
    {
        return damage;
    }

private:
    int damage;
};

int ExecuteAttack(const IAttackBehavior& behavior)
{
    return behavior.CalculateDamage();
}

int main()
{
    MeleeAttack meleeAttack(20);
    std::cout << ExecuteAttack(meleeAttack) << '\n';
}
