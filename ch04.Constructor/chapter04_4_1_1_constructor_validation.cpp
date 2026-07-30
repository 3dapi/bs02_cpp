#include <iostream>

struct Point
{
    int x, y;
};

class Circle
{
public:
    Circle(int x, int y, int radius)
    {
        center.x = x;
        center.y = y;

        if (radius > 0)
        {
            this->radius = radius;
        }
        else
        {
            this->radius = 1;
        }
    }

    void Print() const
    {
        std::cout << center.x << ", " << center.y
                  << " / " << radius << '\n';
    }

private:
    Point center;
    int radius;
};

int main()
{
    Circle first(10, 20, 30);
    Circle second(10, 20, -5);

    first.Print();
    second.Print();
}
