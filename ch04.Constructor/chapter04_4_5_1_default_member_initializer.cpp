#include <iostream>

struct Point
{
    int x, y;
};

class Rectangle
{
public:
    Rectangle() = default;

    Rectangle(int width, int height)
        : width(width), height(height)
    {
    }

    Rectangle(Point position, int width, int height)
        : position(position), width(width), height(height)
    {
    }

    void Print() const
    {
        std::cout << position.x << ", " << position.y
                  << " / " << width << " x " << height << '\n';
    }

private:
    Point position{0, 0};
    int width = 1;
    int height = 1;
};

int main()
{
    Rectangle first;
    Rectangle second(100, 50);
    Rectangle third({10, 20}, 200, 100);

    first.Print();
    second.Print();
    third.Print();
}
