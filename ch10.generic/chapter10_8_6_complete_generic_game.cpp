#include <algorithm>
#include <concepts>
#include <iostream>
#include <memory>
#include <string>
#include <string_view>
#include <utility>

class HealthComponent
{
public:
    explicit HealthComponent(int maxHp)
        : hp(maxHp), maxHp(maxHp)
    {
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

    int GetHp() const noexcept
    {
        return hp;
    }

    bool IsDead() const noexcept
    {
        return hp == 0;
    }

private:
    int hp;
    int maxHp;
};

class GameObject
{
public:
    virtual ~GameObject() = default;

    virtual void Update() = 0;
    virtual std::string_view GetName() const noexcept = 0;
};

class Player : public GameObject
{
public:
    Player(std::string name, int maxHp)
        : name(std::move(name)), health(maxHp)
    {
    }

    void Update() override
    {
        std::cout << name << " handles player input\n";
    }

    std::string_view GetName() const noexcept override
    {
        return name;
    }

    int TakeDamage(int damage)
    {
        return health.TakeDamage(damage);
    }

    int GetHp() const noexcept
    {
        return health.GetHp();
    }

    bool IsDead() const noexcept
    {
        return health.IsDead();
    }

private:
    std::string name;
    HealthComponent health;
};

class Monster : public GameObject
{
public:
    Monster(std::string name, int maxHp, int attackPower)
        : name(std::move(name)),
          health(maxHp),
          attackPower(attackPower)
    {
    }

    void Update() override
    {
        std::cout << name << " runs AI behavior\n";
    }

    std::string_view GetName() const noexcept override
    {
        return name;
    }

    int TakeDamage(int damage)
    {
        return health.TakeDamage(damage);
    }

    int GetHp() const noexcept
    {
        return health.GetHp();
    }

    bool IsDead() const noexcept
    {
        return health.IsDead();
    }

    int GetAttackPower() const noexcept
    {
        return attackPower;
    }

private:
    std::string name;
    HealthComponent health;
    int attackPower;
};

template <typename T>
concept Damageable = requires(T& target,
                              const T& constTarget,
                              int damage)
{
    { target.TakeDamage(damage) } -> std::same_as<int>;
    { constTarget.GetHp() } noexcept -> std::same_as<int>;
    { constTarget.IsDead() } noexcept -> std::same_as<bool>;
};

template <Damageable Target>
int ApplyDamage(Target& target, int damage)
{
    return target.TakeDamage(damage);
}

template <typename T, typename... Args>
requires std::derived_from<T, GameObject> &&
         std::constructible_from<T, Args...>
std::unique_ptr<GameObject> CreateGameObject(Args&&... args)
{
    return std::make_unique<T>(
        std::forward<Args>(args)...);
}

template <typename... Objects>
requires (std::derived_from<Objects, GameObject> && ...)
void UpdateObjects(Objects&... objects)
{
    (objects.Update(), ...);
}

int main()
{
    Player player("Knight", 150);
    Monster monster("Goblin", 80, 12);

    UpdateObjects(player, monster);

    const int appliedDamage = ApplyDamage(monster, 35);

    std::cout << monster.GetName()
              << " damage=" << appliedDamage
              << " hp=" << monster.GetHp()
              << '\n';

    std::unique_ptr<GameObject> objects[]
    {
        CreateGameObject<Player>("Mage", 100),
        CreateGameObject<Monster>("Orc", 120, 18)
    };

    for (const auto& object : objects)
    {
        object->Update();
    }
}
