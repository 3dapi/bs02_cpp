#include <iostream>

class Weapon
{
public:
    int GetPower() const
    {
        return power;
    }

private:
    int power = 20;
};

class Player
{
public:
    void EquipWeapon(Weapon* newWeapon);

    int GetAttackPower() const
    {
        if (weapon == nullptr)
        {
            return 1;
        }

        return weapon->GetPower();
    }

private:
    Weapon* weapon = nullptr;
};

void Player::EquipWeapon(Weapon* newWeapon)
{
    weapon = newWeapon;
}

int main()
{
    Player player;
    Weapon weapon;

    player.EquipWeapon(&weapon);

    std::cout << player.GetAttackPower() << '\n';
}
