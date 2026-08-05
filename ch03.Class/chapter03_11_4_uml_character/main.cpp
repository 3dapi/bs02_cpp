#include <iostream>
#include "Character.h"

int main()
{
    Character character("Warrior");

    character.Move(10.0f, 20.0f);
    character.TakeDamage(30);

    const Vector2& position = character.GetPosition();

    std::cout << "Name: "
              << character.GetName() << '\n';

    std::cout << "Position: "
              << position.x << ", "
              << position.y << '\n';

    std::cout << "HP: "
              << character.GetHp() << '\n';

    return 0;
}
