#include <iostream>

struct Point
{
    int x, y;
};

int main()
{
    Point point{10, 20};
    Point* first = &point;
    Point* second = first;

    second->x = 100;

    std::cout << first->x << '\n';
}
