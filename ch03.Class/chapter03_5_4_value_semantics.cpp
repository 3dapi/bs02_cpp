#include <iostream>

struct Position
{
    int x, y;

    void Move(int offsetX, int offsetY)
    {
        x += offsetX;
        y += offsetY;
    }

    bool IsOrigin() const
    {
        return x == 0 && y == 0;
    }
};

int main()
{
    Position first;

    first.x = 10;
    first.y = 20;

    Position second = first;
    second.x = 50;

    std::cout << first.x << ", " << first.y << '\n';
    std::cout << second.x << ", " << second.y << '\n';
}
