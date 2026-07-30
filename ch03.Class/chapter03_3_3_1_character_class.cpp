#include <iostream>

class Character
{
public:
    void Move(int x, int y);
    void Attack();
    void TakeDamage(int damage);
    int GetHp() const;

private:
    int hp = 100;
    int x = 0, y = 0;
    int attackPower = 10;
};

void Character::Move(int x, int y)
{
    this->x += x;
    this->y += y;
}

void Character::Attack()
{
    std::cout << "Attack: " << attackPower << '\n';
}

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

    character.Move(10, 20);
    character.Attack();
    character.TakeDamage(30);

    std::cout << character.GetHp() << '\n';
}
