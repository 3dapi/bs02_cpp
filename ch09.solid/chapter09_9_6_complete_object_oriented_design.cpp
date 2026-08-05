#include <algorithm>
#include <cassert>
#include <iostream>
#include <memory>
#include <random>
#include <sstream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

class IRandomSource
{
public:
    virtual ~IRandomSource() = default;
    virtual int NextInt(int min, int max) = 0;
};

class MtRandomSource : public IRandomSource
{
public:
    MtRandomSource()
        : engine(std::random_device{}())
    {
    }

    int NextInt(int min, int max) override
    {
        std::uniform_int_distribution<int> distribution(min, max);
        return distribution(engine);
    }

private:
    std::mt19937 engine;
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

class ICombatLog
{
public:
    virtual ~ICombatLog() = default;
    virtual void Write(std::string_view message) = 0;
};

class ConsoleCombatLog : public ICombatLog
{
public:
    void Write(std::string_view message) override
    {
        std::cout << message << '\n';
    }
};

class MemoryCombatLog : public ICombatLog
{
public:
    void Write(std::string_view message) override
    {
        messages.emplace_back(message);
    }

    const std::vector<std::string>& GetMessages() const
    {
        return messages;
    }

private:
    std::vector<std::string> messages;
};

class HealthComponent
{
public:
    explicit HealthComponent(int maxHp)
        : hp(maxHp), maxHp(maxHp)
    {
        if (maxHp <= 0)
        {
            throw std::invalid_argument(
                "maxHp must be positive");
        }
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

    int GetHp() const
    {
        return hp;
    }

    int GetMaxHp() const
    {
        return maxHp;
    }

    bool IsDead() const
    {
        return hp == 0;
    }

private:
    int hp;
    int maxHp;
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
    MeleeAttack(int baseDamage, int criticalRate)
        : baseDamage(std::max(baseDamage, 0)),
          criticalRate(std::clamp(criticalRate, 0, 100))
    {
    }

    AttackRoll Roll(IRandomSource& randomSource) const override
    {
        const bool critical =
            randomSource.NextInt(1, 100) <= criticalRate;

        return AttackRoll
        {
            critical ? baseDamage * 2 : baseDamage,
            critical,
            "MeleeAttack"
        };
    }

private:
    int baseDamage;
    int criticalRate;
};

class RangedAttack : public IAttackBehavior
{
public:
    RangedAttack(int minDamage, int maxDamage)
        : minDamage(std::max(minDamage, 0)),
          maxDamage(std::max(maxDamage, this->minDamage))
    {
    }

    AttackRoll Roll(IRandomSource& randomSource) const override
    {
        return AttackRoll
        {
            randomSource.NextInt(minDamage, maxDamage),
            false,
            "RangedAttack"
        };
    }

private:
    int minDamage;
    int maxDamage;
};

class Character
{
public:
    Character(std::string name,
              int maxHp,
              std::unique_ptr<IAttackBehavior> attackBehavior)
        : name(std::move(name)),
          health(maxHp),
          attackBehavior(std::move(attackBehavior))
    {
        if (this->attackBehavior == nullptr)
        {
            throw std::invalid_argument(
                "attackBehavior is null");
        }
    }

    virtual ~Character() = default;

    Character(const Character&) = delete;
    Character& operator=(const Character&) = delete;
    Character(Character&&) noexcept = default;
    Character& operator=(Character&&) noexcept = default;

    AttackRoll RollAttack(IRandomSource& randomSource) const
    {
        return attackBehavior->Roll(randomSource);
    }

    void ChangeAttack(
        std::unique_ptr<IAttackBehavior> newBehavior)
    {
        if (newBehavior == nullptr)
        {
            throw std::invalid_argument(
                "newBehavior is null");
        }

        attackBehavior = std::move(newBehavior);
    }

    int TakeDamage(int damage)
    {
        return health.TakeDamage(damage);
    }

    std::string_view GetName() const
    {
        return name;
    }

    int GetHp() const
    {
        return health.GetHp();
    }

    int GetMaxHp() const
    {
        return health.GetMaxHp();
    }

    bool IsDead() const
    {
        return health.IsDead();
    }

private:
    std::string name;
    HealthComponent health;
    std::unique_ptr<IAttackBehavior> attackBehavior;
};

class Player final : public Character
{
public:
    using Character::Character;
};

class Monster final : public Character
{
public:
    using Character::Character;
};

class CombatService
{
public:
    CombatService(IRandomSource& randomSource,
                  ICombatLog& combatLog)
        : randomSource(randomSource),
          combatLog(combatLog)
    {
    }

    void Attack(Character& attacker, Character& target)
    {
        if (attacker.IsDead() || target.IsDead())
        {
            return;
        }

        const AttackRoll roll =
            attacker.RollAttack(randomSource);

        const int actualDamage =
            target.TakeDamage(roll.damage);

        std::ostringstream output;
        output << attacker.GetName()
               << " uses " << roll.attackName
               << " on " << target.GetName()
               << " for " << actualDamage
               << " damage";

        if (roll.critical)
        {
            output << " critical";
        }

        output << " hp=" << target.GetHp();
        combatLog.Write(output.str());
    }

private:
    IRandomSource& randomSource;
    ICombatLog& combatLog;
};

void TestCriticalAttack()
{
    FixedRandomSource randomSource(10);
    MemoryCombatLog combatLog;
    CombatService combatService(randomSource, combatLog);

    Player player(
        "Knight",
        150,
        std::make_unique<MeleeAttack>(20, 20));

    Monster monster(
        "Goblin",
        100,
        std::make_unique<MeleeAttack>(10, 0));

    combatService.Attack(player, monster);

    assert(monster.GetHp() == 60);
    assert(combatLog.GetMessages().size() == 1);
}

int main()
{
    TestCriticalAttack();

    MtRandomSource randomSource;
    ConsoleCombatLog combatLog;
    CombatService combatService(randomSource, combatLog);

    Player player(
        "Knight",
        150,
        std::make_unique<MeleeAttack>(20, 20));

    Monster monster(
        "Goblin",
        100,
        std::make_unique<RangedAttack>(8, 14));

    combatService.Attack(player, monster);
    combatService.Attack(monster, player);

    player.ChangeAttack(
        std::make_unique<RangedAttack>(15, 25));

    combatService.Attack(player, monster);
}
