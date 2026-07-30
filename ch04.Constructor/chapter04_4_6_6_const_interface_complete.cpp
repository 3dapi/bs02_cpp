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

    void MoveTo(Point position)
    {
        this->position = position;
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
    }

    int Area() const
    {
        ++areaQueryCount;
        return width * height;
    }

    Point& Position()
    {
        return position;
    }

    const Point& Position() const
    {
        return position;
    }

    int AreaQueryCount() const
    {
        return areaQueryCount;
    }

private:
    Point position;
    int width;
    int height;
    mutable int areaQueryCount = 0;
};

int main()
{
    Rectangle rectangle({10, 20}, 100, 50);
    rectangle.MoveTo({30, 40});
    rectangle.Resize(200, 100);
    rectangle.Position().x = 50;

    std::cout << rectangle.Area() << '\n';

    const Rectangle fixedRectangle({10, 20}, 100, 50);
    std::cout << fixedRectangle.Area() << '\n';
    std::cout << fixedRectangle.Position().x << '\n';
}
