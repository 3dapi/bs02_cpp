#include <iostream>

struct Point
{
    int x, y;
};

int main()
{
    Point original{10, 20};
    Point copy = original;

    copy.x = 100;

    std::cout << original.x << '\n';
    std::cout << copy.x << '\n';
}
