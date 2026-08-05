#include <iostream>

struct Point
{
    int x;
    int y;
};

int main()
{
    int* value = new int();
    Point* point = new Point();

    std::cout << *value << '\n';
    std::cout << point->x << ", " << point->y << '\n';

    delete value;
    delete point;
}
