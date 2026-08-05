#include <iostream>

struct Point
{
    int x;
    int y;
};

int main()
{
    int count{};
    double ratio{};
    Point point{};

    std::cout << count << '\n';
    std::cout << ratio << '\n';
    std::cout << point.x << ", " << point.y << '\n';
}
