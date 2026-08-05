#include <iostream>

struct Point
{
    int x, y;
};

class Rectangle
{
public:
    Rectangle()
        : Rectangle({0, 0}, 1, 1)
    {
    }

    Rectangle(int width, int height)
        : Rectangle({0, 0}, width, height)
    {
    }

    Rectangle(Point position, int width, int height)
        : position(position), width(width), height(height)
    {
        if (this->width <= 0)
        {
            this->width = 1;
        }

        if (this->height <= 0)
        {
            this->height = 1;
        }
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
    Rectangle first;
    Rectangle second(-10, 50);
    Rectangle third({10, 20}, 100, 50);

    first.Print();
    second.Print();
    third.Print();
}
