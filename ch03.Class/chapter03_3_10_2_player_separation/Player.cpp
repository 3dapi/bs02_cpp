#include "Player.h"
#include "Weapon.h"

Player::Player(const std::string& name)
    : name(name)
{
}

void Player::Move(float offsetX, float offsetY)
{
    position.x += offsetX;
    position.y += offsetY;
}

void Player::TakeDamage(int damage)
{
    if (damage <= 0)
    {
        return;
    }

    hp -= damage;

    if (hp < 0)
    {
        hp = 0;
    }
}

void Player::EquipWeapon(Weapon* newWeapon)
{
    weapon = newWeapon;
}

int Player::GetHp() const
{
    return hp;
}

int Player::GetAttackPower() const
{
    if (weapon == nullptr)
    {
        return 1;
    }

    return weapon->GetAttackPower();
}

const std::string& Player::GetName() const
{
    return name;
}

const Vector2& Player::GetPosition() const
{
    return position;
}
