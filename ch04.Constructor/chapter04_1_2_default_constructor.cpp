#include <iostream>

struct Point
{
    int x, y;
};

class Rectangle
{
public:
    Rectangle()
    {
        position.x = 0;
        position.y = 0;
        width = 1;
        height = 1;
    }

    int Area() const
    {
        return width * height;
    }

private:
    Point position;
    int width;
    int height;
};

int main()
{
    Rectangle first;
    Rectangle second{};

    std::cout << first.Area() << '\n';
    std::cout << second.Area() << '\n';
}
