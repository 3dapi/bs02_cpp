#include <iostream>

struct Point
{
    int x, y;
};

int main()
{
    Point first{10, 20};
    Point second(first);

    std::cout << second.x << ", " << second.y << '\n';
}
