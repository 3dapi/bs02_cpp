#include <iostream>

class Character
{
public:
    void TakeDamage(int damage)
    {
        hp -= damage;
    }

    int GetHp() const
    {
        return hp;
    }

protected:
    int hp = 100;
};

class Monster : public Character
{
};

void PrintHp(const Character& character)
{
    std::cout << character.GetHp() << '\n';
}

int main()
{
    Monster monster;
    monster.TakeDamage(10);
    PrintHp(monster);
}
