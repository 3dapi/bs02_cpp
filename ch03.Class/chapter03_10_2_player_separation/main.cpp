#include <iostream>
#include "Player.h"
#include "Weapon.h"

int main()
{
    Player player("Warrior");
    Weapon weapon(20);

    player.EquipWeapon(&weapon);
    player.Move(10.0f, 20.0f);
    player.TakeDamage(30);

    std::cout << player.GetName() << '\n';
    std::cout << player.GetPosition().x << ", "
              << player.GetPosition().y << '\n';
    std::cout << player.GetHp() << '\n';
    std::cout << player.GetAttackPower() << '\n';
}
