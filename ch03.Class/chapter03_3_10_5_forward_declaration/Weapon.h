#pragma once

class Weapon
{
public:
    explicit Weapon(int attackPower)
        : attackPower(attackPower)
    {
    }

    int GetAttackPower() const
    {
        return attackPower;
    }

private:
    int attackPower = 10;
};
