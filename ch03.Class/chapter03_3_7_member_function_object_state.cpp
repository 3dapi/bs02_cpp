#include <iostream>

struct Vector2
{
    float x, y;
};

class Player
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

public:
    Vector2 position = { 0.0f, 0.0f };
};

int main()
{
    Player first;
    Player second;

    first.Move(10.0f, 20.0f);
    second.Move(-5.0f, 30.0f);

    std::cout << first.GetPosition().x << ", "
              << first.GetPosition().y << '\n';

    std::cout << second.GetPosition().x << ", "
              << second.GetPosition().y << '\n';
}
