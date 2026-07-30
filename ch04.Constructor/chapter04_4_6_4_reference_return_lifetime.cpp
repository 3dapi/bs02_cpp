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

    const Point& Position() const
    {
        return position;
    }

private:
    Point position;
    int width;
    int height;
};

const Point& GetPosition(const Rectangle& rectangle)
{
    return rectangle.Position();
}

int main()
{
    Rectangle rectangle({10, 20}, 100, 50);
    const Point& position = GetPosition(rectangle);

    std::cout << position.x << ", " << position.y << '\n';
}
