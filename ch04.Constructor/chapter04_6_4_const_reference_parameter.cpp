#include <iostream>

struct Point
{
    int x, y;
};

class Rectangle
{
public:
    Rectangle(Point position, int width, int height)
        : position(position), width(width), height(height)
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

void PrintArea(const Rectangle& rectangle)
{
    std::cout << rectangle.Area() << '\n';
}

int main()
{
    Rectangle rectangle({10, 20}, 100, 50);
    const Rectangle fixedRectangle({0, 0}, 200, 100);

    PrintArea(rectangle);
    PrintArea(fixedRectangle);
}
