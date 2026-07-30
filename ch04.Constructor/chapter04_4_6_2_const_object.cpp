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
    const Rectangle rectangle({10, 20}, 100, 50);

    std::cout << rectangle.Area() << '\n';
    // rectangle.MoveTo({30, 40});   // 오류
}
