#include <iostream>

struct Point
{
    int x;
    int y;

    constexpr Point(int x, int y)
        : x(x), y(y)
    {
    }
};

class Rectangle
{
public:
    constexpr Rectangle(Point position, int width, int height)
        : position(position), width(width), height(height)
    {
    }

    constexpr int Area() const
    {
        return width * height;
    }

    constexpr Point Position() const
    {
        return position;
    }

private:
    Point position;
    int width;
    int height;
};

int main()
{
    constexpr Rectangle rectangle({10, 20}, 100, 50);
    constexpr int area = rectangle.Area();

    static_assert(area == 5000);
    static_assert(rectangle.Position().x == 10);

    std::cout << area << '\n';
}
