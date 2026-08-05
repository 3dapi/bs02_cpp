#include <iostream>

struct Character
{
    int hp = 100;
};

void TakeDamage(Character* character, int damage)
{
    if (character->hp -= damage; character->hp < 0)
    {
        character->hp = 0;
    }
}

int main()
{
    Character character;

    TakeDamage(&character, 30);
    std::cout << character.hp << '\n';
}
