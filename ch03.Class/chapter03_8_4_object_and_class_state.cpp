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

    static void SetMovementLimit(float value)
    {
        if (value > 0.0f)
        {
            movementLimit = value;
        }
    }

    static float GetMovementLimit()
    {
        return movementLimit;
    }

    const Vector2& GetPosition() const
    {
        return position;
    }

private:
    Vector2 position = { 0.0f, 0.0f };
    int hp = 100, level = 1;

    inline static float movementLimit = 1000.0f;
};

int main()
{
    Player first;
    Player second;

    first.Move(10.0f, 20.0f);
    second.Move(-5.0f, 30.0f);

    Player::SetMovementLimit(2000.0f);

    std::cout << first.GetPosition().x << '\n';
    std::cout << second.GetPosition().x << '\n';
    std::cout << Player::GetMovementLimit() << '\n';
}
