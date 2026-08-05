#include <iostream>

struct Point
{
    int x, y;
};

int main()
{
    Point point{10, 20};
    Point& first = point;
    Point& second = point;

    first.x = 100;

    std::cout << point.x << '\n';
    std::cout << second.x << '\n';
}
