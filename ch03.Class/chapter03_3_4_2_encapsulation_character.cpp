#include <iostream>

class Character
{
public:
    void TakeDamage(int damage)
    {
        if (hp -= damage; hp < 0)
        {
            hp = 0;
        }
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

    character.TakeDamage(150);
    std::cout << character.GetHp() << '\n';
}
