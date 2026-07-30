#include <iostream>

struct Point
{
    int x, y;
};

class Rectangle
{
public:
    Rectangle()
    {
        position.x = 0;
        position.y = 0;
        width = 1;
        height = 1;
    }

    void Print() const
    {
        std::cout << position.x << ", " << position.y << '\n';
        std::cout << width << " x " << height << '\n';
    }

private:
    Point position;
    int width;
    int height;
};

int main()
{
    Rectangle rectangle;
    rectangle.Print();
}
