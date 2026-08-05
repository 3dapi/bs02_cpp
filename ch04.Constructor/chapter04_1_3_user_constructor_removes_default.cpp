#include <iostream>

struct Point
{
    int x, y;
};

class Rectangle
{
public:
    Rectangle(int x, int y, int width, int height)
    {
        position.x = x;
        position.y = y;
        this->width = width;
        this->height = height;
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
    Rectangle second(10, 20, 100, 50);

    std::cout << second.Area() << '\n';
}
