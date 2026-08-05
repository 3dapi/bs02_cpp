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

    void Print() const
    {
        std::cout << position.x << ", " << position.y
                  << " / " << width << " x " << height << '\n';
    }

private:
    Point position;
    int width;
    int height;
};

int main()
{
    Rectangle rectangle(10, 20, 100, 50);
    rectangle.Print();
}
