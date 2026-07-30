#include <iostream>

struct Position
{
    int x, y;
};

void PrintPosition(const Position& position)
{
    std::cout << position.x << ", "
              << position.y << '\n';
}

Position MovePosition(const Position& position, int offsetX, int offsetY)
{
    Position result;

    result.x = position.x + offsetX;
    result.y = position.y + offsetY;

    return result;
}

int main()
{
    Position playerPosition;

    playerPosition.x = 100;
    playerPosition.y = 200;

    Position movedPosition = MovePosition(playerPosition, 10, -20);

    PrintPosition(playerPosition);
    PrintPosition(movedPosition);
}
