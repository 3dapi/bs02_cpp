#include <iostream>

struct Point
{
    int x, y;
};

class Rectangle
{
public:
    Rectangle() = delete;

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

int main()
{
    // Rectangle first;   // 오류
    Rectangle second({10, 20}, 100, 50);

    std::cout << second.Area() << '\n';
}
