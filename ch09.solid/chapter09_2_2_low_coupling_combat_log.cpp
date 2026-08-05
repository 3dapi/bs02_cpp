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
        hp = std::max(hp - std::max(damage, 0), 0);
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
    explicit CombatService(ICombatLog& combatLog)
        : combatLog(combatLog)
    {
    }

    void Attack(Character& attacker, Character& target)
    {
        const int damage = 20;
        const int actualDamage = target.TakeDamage(damage);

        std::ostringstream output;
        output << attacker.GetName()
               << " attacks "
               << target.GetName()
               << " for "
               << actualDamage
               << " damage";

        combatLog.Write(output.str());
    }

private:
    ICombatLog& combatLog;
};

int main()
{
    ConsoleCombatLog combatLog;
    CombatService combatService(combatLog);
    Character attacker("Knight", 100);
    Character target("Goblin", 100);

    combatService.Attack(attacker, target);
}
