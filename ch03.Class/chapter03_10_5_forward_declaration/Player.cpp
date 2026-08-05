#include "Player.h"
#include "Weapon.h"

void Player::EquipWeapon(Weapon* newWeapon)
{
    weapon = newWeapon;
}

int Player::GetAttackPower() const
{
    if (weapon == nullptr)
    {
        return 1;
    }

    return weapon->GetAttackPower();
}
