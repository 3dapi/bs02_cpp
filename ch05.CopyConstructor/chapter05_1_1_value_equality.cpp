#include <iostream>

struct Point
{
    int x, y;
};

int main()
{
    Point first{10, 20};
    Point second{10, 20};

    bool sameValue =
        first.x == second.x && first.y == second.y;

    std::cout << std::boolalpha << sameValue << '\n';
}
