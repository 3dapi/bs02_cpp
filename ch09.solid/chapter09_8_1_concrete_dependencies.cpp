#include <algorithm>
#include <iostream>
#include <random>
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

class CombatService
{
public:
    CombatService()
        : engine(std::random_device{}())
    {
    }

    void Attack(Character& attacker, Character& target)
    {
        std::uniform_int_distribution<int> distribution(1, 100);
        const bool critical = distribution(engine) <= 20;
        const int damage = critical ? 40 : 20;
        const int actualDamage = target.TakeDamage(damage);

        std::cout << attacker.GetName()
                  << " dealt "
                  << actualDamage
                  << " damage\n";
    }

private:
    std::mt19937 engine;
};

int main()
{
    Character attacker("Knight", 100);
    Character target("Goblin", 100);
    CombatService combatService;

    combatService.Attack(attacker, target);
}
