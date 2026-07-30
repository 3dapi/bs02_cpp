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

    void Resize(int width, int height)
    {
        if (width > 0)
        {
            this->width = width;
        }

        if (height > 0)
        {
            this->height = height;
        }

        areaCached = false;
    }

    int Area() const
    {
        if (!areaCached)
        {
            cachedArea = width * height;
            areaCached = true;
        }

        return cachedArea;
    }

private:
    Point position;
    int width;
    int height;

    mutable bool areaCached = false;
    mutable int cachedArea = 0;
};

int main()
{
    Rectangle rectangle({10, 20}, 100, 50);

    std::cout << rectangle.Area() << '\n';

    rectangle.Resize(200, 100);
    std::cout << rectangle.Area() << '\n';
}
