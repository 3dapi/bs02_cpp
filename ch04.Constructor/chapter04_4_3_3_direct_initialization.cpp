#include <iostream>

struct Point
{
    int x, y;
};

class Rectangle
{
public:
    Rectangle(int x, int y, int width, int height)
        : position{ x, y }, width(width), height(height)
    {
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
    Rectangle first(10, 20, 100, 50);
    Rectangle second{10, 20, 100, 50};

    std::cout << first.Area() << '\n';
    std::cout << second.Area() << '\n';
}
