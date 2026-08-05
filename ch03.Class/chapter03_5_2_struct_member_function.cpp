#include <iostream>

struct Position
{
    int x, y;

    void Move(int offsetX, int offsetY)
    {
        x += offsetX;
        y += offsetY;
    }
};

int main()
{
    Position position;

    position.x = 10;
    position.y = 20;
    position.Move(5, -10);

    std::cout << position.x << ", "
              << position.y << '\n';
}
