#include <iostream>

struct Point
{
    int x = 0, y = 0;
};

class Rectangle
{
public:
    Rectangle() = default;
    ~Rectangle() = default;

    int Area() const
    {
        return width * height;
    }

private:
    Point position{0, 0};
    int width = 1;
    int height = 1;
};

int main()
{
    Rectangle rectangle;
    std::cout << rectangle.Area() << '\n';
}
