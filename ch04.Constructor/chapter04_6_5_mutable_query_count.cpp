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
        ++areaQueryCount;
        return width * height;
    }

    int AreaQueryCount() const
    {
        return areaQueryCount;
    }

private:
    Point position;
    int width;
    int height;
    mutable int areaQueryCount = 0;
};

int main()
{
    const Rectangle rectangle({10, 20}, 100, 50);

    int first = rectangle.Area();
    int second = rectangle.Area();

    std::cout << first << ", " << second << '\n';
    std::cout << rectangle.AreaQueryCount() << '\n';
}
