#include <iostream>

struct Point
{
    int x, y;
};

class Shape
{
public:
    Shape(Point position)
        : position(position)
    {
    }

protected:
    Point position;
};

class Rectangle : public Shape
{
public:
    Rectangle(Point position, int width, int height)
        : Shape(position), width(width), height(height)
    {
    }

    void Print() const
    {
        std::cout << position.x << ", " << position.y
                  << " / " << width << " x " << height << '\n';
    }

private:
    int width;
    int height;
};

int main()
{
    Rectangle rectangle({10, 20}, 100, 50);
    rectangle.Print();
}
