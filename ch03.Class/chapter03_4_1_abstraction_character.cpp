#include <iostream>

class Character
{
public:
    void Move()
    {
        std::cout << "Move\n";
    }

    void Attack()
    {
        std::cout << "Attack\n";
    }

private:
    int hp = 100;
};

int main()
{
    Character character;

    character.Move();
    character.Attack();
}
