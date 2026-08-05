#include <iostream>

class IDamageable
{
public:
    virtual ~IDamageable() = default;
    virtual void TakeDamage(int damage) = 0;
};

class Character : public IDamageable
{
public:
    void TakeDamage(int damage) override
    {
        if (damage > 0)
        {
            hp -= damage;
        }
    }

    int GetHp() const
    {
        return hp;
    }

private:
    int hp = 100;
};

void ApplyDamage(IDamageable& target, int damage)
{
    target.TakeDamage(damage);
}

int main()
{
    Character character;
    ApplyDamage(character, 25);
    std::cout << character.GetHp() << '\n';
}
