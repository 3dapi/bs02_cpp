#include <iostream>
#include "Vector2.h"

int main()
{
    Vector2 position;

    position.x = 10.0f;
    position.y = 20.0f;

    std::cout << position.x << ", "
              << position.y << '\n';
}
