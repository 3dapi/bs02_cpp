#include <algorithm>
#include <iostream>
#include <string>
#include <utility>

class Character
{
public:
    Character(std::string name, int maxHp)
        : name(std::move(name)), hp(std::max(maxHp, 0)), maxHp(std::max(maxHp, 0))
    {
    }

    virtual ~Character() = default;

    void TakeDamage(int damage)
    {
        if (damage > 0)
        {
            hp = std::max(hp - damage, 0);
        }
    }

    int GetHp() const
    {
        return hp;
    }

    int GetMaxHp() const
    {
        return maxHp;
    }

    const std::string& GetName() const
    {
        return name;
    }

private:
    std::string name;
    int hp;
    int maxHp;
};

class MobBase : public Character
{
public:
    MobBase(std::string name, int maxHp, int attackPower)
        : Character(std::move(name), maxHp),
          attackPower(std::max(attackPower, 0))
    {
    }

    virtual void Think() = 0;
    virtual void Attack(Character& target) = 0;

protected:
    int GetAttackPower() const
    {
        return attackPower;
    }

private:
    int attackPower;
};

class Monster : public MobBase
{
public:
    Monster(std::string name, int maxHp, int attackPower)
        : MobBase(std::move(name), maxHp, attackPower)
    {
    }

    void Think() override
    {
        std::cout << GetName() << " patrols\n";
    }

    void Attack(Character& target) override
    {
        target.TakeDamage(GetAttackPower());
    }
};

class BossMonster : public MobBase
{
public:
    BossMonster(std::string name, int maxHp, int attackPower)
        : MobBase(std::move(name), maxHp, attackPower)
    {
    }

    void Think() override
    {
        std::cout << GetName() << " phase " << phase << '\n';
    }

    void Attack(Character& target) override
    {
        target.TakeDamage(GetAttackPower() * phase);
    }

private:
    int phase = 1;
};

int main()
{
    Monster monster("Goblin", 60, 10);
    BossMonster boss("Dragon", 900, 30);

    monster.Think();
    boss.Think();
    boss.Attack(monster);

    std::cout << monster.GetHp() << '\n';
}
