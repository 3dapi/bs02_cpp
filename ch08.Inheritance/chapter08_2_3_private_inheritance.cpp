#include <iostream>

class MovementService
{
public:
    void Move(float x, float y) const
    {
        std::cout << "move: " << x << ", " << y << '\n';
    }
};

class PlayerController : private MovementService
{
public:
    void MovePlayer(float x, float y) const
    {
        Move(x, y);
    }
};

int main()
{
    PlayerController controller;
    controller.MovePlayer(10.0f, 20.0f);
}
