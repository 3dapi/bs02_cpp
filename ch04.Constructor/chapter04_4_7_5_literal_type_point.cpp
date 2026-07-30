#include <iostream>

struct Point
{
    int x, y;

    constexpr Point(int x, int y)
        : x(x), y(y)
    {
    }
};

int main()
{
    constexpr Point origin(0, 0);

    static_assert(origin.x == 0 && origin.y == 0);
    std::cout << origin.x << ", " << origin.y << '\n';
}
