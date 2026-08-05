#include <iostream>

struct Point
{
    int x, y;
};

int main()
{
    Point first{10, 20};
    Point second = first;

    second.x = 100;

    std::cout << first.x << ", " << first.y << '\n';
    std::cout << second.x << ", " << second.y << '\n';
}
