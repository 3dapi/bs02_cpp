#include <concepts>
#include <iostream>

class Health
{
public:
    using HealthType = int;

    Health() = default;

    int TakeDamage(int damage)
    {
        hp -= damage;
        return damage;
    }

    int GetHp() const noexcept
    {
        return hp;
    }

    bool IsDead() const noexcept
    {
        return hp <= 0;
    }

private:
    int hp = 100;
};

template <typename T>
concept ReadableHealth = requires(const T& value)
{
    { value.GetHp() } noexcept -> std::same_as<int>;
};

template <typename T>
concept SmallObject = requires
{
    requires sizeof(T) <= 64;
};

template <typename T>
concept Damageable = requires(T& target,
                              const T& constTarget,
                              int damage)
{
    typename T::HealthType;
    { target.TakeDamage(damage) } -> std::same_as<int>;
    { constTarget.GetHp() } noexcept -> std::same_as<int>;
    { constTarget.IsDead() } noexcept -> std::same_as<bool>;
    requires std::default_initializable<typename T::HealthType>;
};

int main()
{
    static_assert(ReadableHealth<Health>);
    static_assert(SmallObject<Health>);
    static_assert(Damageable<Health>);

    Health health;
    std::cout << health.GetHp() << '\n';
}
