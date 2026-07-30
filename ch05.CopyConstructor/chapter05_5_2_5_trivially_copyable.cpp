#include <cstring>
#include <iostream>
#include <type_traits>

struct Point
{
    int x, y;
};

int main()
{
    static_assert(std::is_trivially_copyable_v<Point>);

    Point first{10, 20};
    Point second{};

    std::memcpy(&second, &first, sizeof(Point));

    std::cout << second.x << ", " << second.y << '\n';
}
