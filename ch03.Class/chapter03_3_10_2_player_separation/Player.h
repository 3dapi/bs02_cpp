#pragma once

#include <string>
#include "Vector2.h"

class Weapon;

class Player
{
public:
    Player(const std::string& name);

    void Move(float offsetX, float offsetY);
    void TakeDamage(int damage);
    void EquipWeapon(Weapon* newWeapon);

    int GetHp() const;
    int GetAttackPower() const;
    const std::string& GetName() const;
    const Vector2& GetPosition() const;

private:
    std::string name;
    Vector2 position;
    Weapon* weapon = nullptr;
    int hp = 100;
};
