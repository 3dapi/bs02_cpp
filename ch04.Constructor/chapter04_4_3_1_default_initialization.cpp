#include <iostream>

struct Point
{
    int x = 0;
    int y = 0;
};

class Rectangle
{
public:
    Rectangle() = default;

    int Area() const
    {
        return width * height;
    }

private:
    Point position;
    int width = 1;
    int height = 1;
};

int main()
{
    Rectangle rectangle;
    std::cout << rectangle.Area() << '\n';
}
