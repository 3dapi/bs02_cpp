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

        if (width > 0)
        {
            this->width = width;
        }
        else
        {
            this->width = 1;
        }

        if (height > 0)
        {
            this->height = height;
        }
        else
        {
            this->height = 1;
        }
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
    Rectangle first(10, 20, 100, 50);
    Rectangle second(0, 0, -10, 480);

    std::cout << first.Area() << '\n';
    std::cout << second.Area() << '\n';
}
