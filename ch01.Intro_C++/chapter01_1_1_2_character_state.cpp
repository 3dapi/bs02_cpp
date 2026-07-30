#include <iostream>

class Character
{
public:
    void TakeDamage(int damage)
    {
        hp -= damage;
        if (hp < 0)
            hp = 0;
    }

    int GetHp() const
    {
        return hp;
    }

private:
    int hp = 100;
};

int main()
{
    Character character;
    character.TakeDamage(30);

    std::cout << character.GetHp() << '\n';
}
