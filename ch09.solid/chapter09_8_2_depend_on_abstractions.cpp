#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <string_view>
#include <utility>

class Character
{
public:
    Character(std::string name, int hp)
        : name(std::move(name)), hp(hp)
    {
    }

    int TakeDamage(int damage)
    {
        const int oldHp = hp;
        hp = std::max(hp - damage, 0);
        return oldHp - hp;
    }

    std::string_view GetName() const
    {
        return name;
    }

private:
    std::string name;
    int hp;
};

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
        const bool critical = randomSource.NextInt(1, 100) <= 20;
        const int damage = critical ? 40 : 20;
        const int actualDamage = target.TakeDamage(damage);

        std::ostringstream output;
        output << attacker.GetName()
               << " dealt "
               << actualDamage
               << " damage";

        combatLog.Write(output.str());
    }

private:
    IRandomSource& randomSource;
    ICombatLog& combatLog;
};

int main()
{
    FixedRandomSource randomSource(10);
    ConsoleCombatLog combatLog;
    CombatService combatService(randomSource, combatLog);
    Character attacker("Knight", 100);
    Character target("Goblin", 100);

    combatService.Attack(attacker, target);
}
