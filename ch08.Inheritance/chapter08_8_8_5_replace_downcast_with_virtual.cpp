#include <iostream>

class Character
{
public:
    virtual ~Character() = default;

    void TakeDamage(int damage)
    {
        hp -= damage;
    }

    int GetHp() const
    {
        return hp;
    }

private:
    int hp = 100;
};

class MobBase : public Character
{
public:
    virtual void Attack(Character& target) = 0;
};

class Monster : public MobBase
{
public:
    void Attack(Character& target) override
    {
        target.TakeDamage(10);
    }
};

void ExecuteAttack(MobBase& mob, Character& target)
{
    mob.Attack(target);
}

int main()
{
    Monster monster;
    Character target;

    ExecuteAttack(monster, target);
    std::cout << target.GetHp() << '\n';
}
