#include <iostream>
#include <utility>

class MeleeAttack
{
public:
    explicit MeleeAttack(int damage)
        : damage(damage)
    {
    }

    int CalculateDamage() const
    {
        return damage;
    }

private:
    int damage;
};

template <typename AttackPolicy>
class AttackProcessor
{
public:
    explicit AttackProcessor(AttackPolicy policy)
        : policy(std::move(policy))
    {
    }

    int Execute() const
    {
        return policy.CalculateDamage();
    }

private:
    AttackPolicy policy;
};

int main()
{
    MeleeAttack meleeAttack(20);
    AttackProcessor<MeleeAttack> processor(meleeAttack);

    std::cout << processor.Execute() << '\n';
}
