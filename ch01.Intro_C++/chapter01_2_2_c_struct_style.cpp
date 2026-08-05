#include <iostream>

struct Item
{
    char name[32];
};

struct Character
{
    int hp;
    int attack;
    Item* pItem;
};

void TakeDamage(Character* character, int damage)
{
    character->hp -= damage;
    if (character->hp < 0)
    {
        character->hp = 0;
    }
}

int main()
{
    Character character{ 100, 20, nullptr };
    TakeDamage(&character, 30);

    std::cout << character.hp << '\n';
}
