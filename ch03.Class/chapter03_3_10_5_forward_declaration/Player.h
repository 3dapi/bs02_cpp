#pragma once

class Weapon;

class Player
{
public:
    void EquipWeapon(Weapon* newWeapon);
    int GetAttackPower() const;

private:
    Weapon* weapon = nullptr;
};
