#include <iostream>

struct Point
{
    int x, y;
};

struct Size
{
    int width;
    int height;
};

struct Area
{
    Point position;
    Size size;
};

int main()
{
    Area area{{10, 20}, {100, 50}};

    std::cout << area.position.x << ", "
              << area.position.y << '\n';
    std::cout << area.size.width << " x "
              << area.size.height << '\n';
}
