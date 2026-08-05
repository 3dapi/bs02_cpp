#include <iostream>

struct Vector2
{
    float x = 0.0f, y = 0.0f;
};

class Character
{
public:
    void Move(float offsetX, float offsetY)
    {
        position.x += offsetX;
        position.y += offsetY;
    }

    const Vector2& GetPosition() const
    {
        return position;
    }

private:
    Vector2 position;
};

int main()
{
    Character character;

    character.Move(10.0f, 20.0f);

    std::cout << character.GetPosition().x << ", "
              << character.GetPosition().y << '\n';
}
