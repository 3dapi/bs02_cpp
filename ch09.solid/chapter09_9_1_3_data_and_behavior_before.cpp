#include <iostream>

class Character
{
public:
    int GetHp() const
    {
        return hp;
    }

    void SetHp(int hp)
    {
        this->hp = hp;
    }

private:
    int hp = 100;
};

void ApplyDamage(Character& target, int damage)
{
    int hp = target.GetHp();
    hp -= damage;

    if (hp < 0)
    {
        hp = 0;
    }

    target.SetHp(hp);
}

int main()
{
    Character target;

    ApplyDamage(target, 120);

    std::cout << target.GetHp() << '\n';
}
