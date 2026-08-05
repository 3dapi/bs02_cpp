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

    Point& Position()
    {
        return position;
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

int main()
{
    Rectangle rectangle({10, 20}, 100, 50);
    rectangle.Position().x = 30;
    rectangle.Position().y = 40;

    const Rectangle fixedRectangle({50, 60}, 200, 100);

    std::cout << rectangle.Position().x << ", "
              << rectangle.Position().y << '\n';
    std::cout << fixedRectangle.Position().x << ", "
              << fixedRectangle.Position().y << '\n';
}
