#include "Character.h"

Character::Character(const std::string& name)
    : name(name)
{
}

void Character::Move(float offsetX, float offsetY)
{
    position.x += offsetX;
    position.y += offsetY;
}

void Character::TakeDamage(int damage)
{
    if (damage <= 0)
    {
        return;
    }
    if (hp -= damage; hp < 0)
    {
        hp = 0;
    }
}

const std::string& Character::GetName() const
{
    return name;
}

const Vector2& Character::GetPosition() const
{
    return position;
}

int Character::GetHp() const
{
    return hp;
}
