#include <iostream>
#include "Player.h"
#include "Weapon.h"

int main()
{
    Player player;
    Weapon weapon(30);

    player.EquipWeapon(&weapon);

    std::cout << player.GetAttackPower() << '\n';
}
