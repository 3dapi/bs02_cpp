#pragma once

#include <string>
#include "Vector2.h"

class Character
{
public:
    Character(const std::string& name);

    void Move(float offsetX, float offsetY);
    void TakeDamage(int damage);

    const std::string& GetName() const;
    const Vector2& GetPosition() const;
    int GetHp() const;

private:
    std::string name;
    Vector2 position;
    int hp = 100;
};
