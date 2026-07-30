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
    Rectangle original(10, 20, 100, 50);
    Rectangle copy = original;

    std::cout << original.Area() << '\n';
    std::cout << copy.Area() << '\n';
}
