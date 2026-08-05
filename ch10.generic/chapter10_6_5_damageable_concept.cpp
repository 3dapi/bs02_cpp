#include <concepts>
#include <iostream>

template <typename T>
concept DamageableObject = requires(T& target, int damage)
{
    { target.TakeDamage(damage) } -> std::convertible_to<int>;
    { target.IsDead() } -> std::convertible_to<bool>;
};

template <DamageableObject T>
int ApplyDamage(T& target, int damage)
{
    if (damage <= 0 || target.IsDead())
    {
        return 0;
    }

    return target.TakeDamage(damage);
}

class Player
{
public:
    int TakeDamage(int damage)
    {
        const int applied = damage > hp ? hp : damage;
        hp -= applied;
        return applied;
    }

    bool IsDead() const
    {
        return hp == 0;
    }

private:
    int hp = 100;
};

class BreakableBox
{
public:
    int TakeDamage(int damage)
    {
        const int applied =
            damage > durability ? durability : damage;
        durability -= applied;
        return applied;
    }

    bool IsDead() const
    {
        return durability == 0;
    }

private:
    int durability = 40;
};

int main()
{
    Player player;
    BreakableBox box;

    std::cout << ApplyDamage(player, 25) << '\n';
    std::cout << ApplyDamage(box, 10) << '\n';
}
