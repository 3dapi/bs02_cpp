#include <iostream>

class Character
{
public:
    void TakeDamage(int damage);
    int GetHp() const;

private:
    int hp = 100;
};

void Character::TakeDamage(int damage)
{
    if (hp -= damage; hp < 0)
    {
        hp = 0;
    }
}

int Character::GetHp() const
{
    return hp;
}

int main()
{
    Character character;

    character.TakeDamage(120);
    std::cout << character.GetHp() << '\n';
}
