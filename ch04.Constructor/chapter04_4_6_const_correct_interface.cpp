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

    void MoveTo(Point position)
    {
        this->position = position;
    }

    void Resize(int width, int height)
    {
        this->width = width;
        this->height = height;
    }

    int Area() const
    {
        return width * height;
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
    rectangle.MoveTo({30, 40});
    rectangle.Resize(200, 100);

    std::cout << rectangle.Area() << '\n';
    std::cout << rectangle.Position().x << '\n';
}
