#include <iostream>

struct Point
{
    int x, y;

    bool operator==(const Point& other) const
    {
        return x == other.x && y == other.y;
    }
};

int main()
{
    Point first{10, 20};
    Point second{10, 20};
    Point third{30, 40};

    std::cout << std::boolalpha;
    std::cout << (first == second) << '\n';
    std::cout << (first != third) << '\n';
}
