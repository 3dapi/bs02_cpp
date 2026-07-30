#include <iostream>

struct Point
{
    int x = 0, y = 0;
};

class Rectangle
{
public:
    void Print() const
    {
        std::cout << position.x << ", " << position.y << '\n';
        std::cout << width << " x " << height << '\n';
    }

private:
    Point position;
    int width = 1;
    int height = 1;
};

int main()
{
    Rectangle rectangle;
    rectangle.Print();
}
