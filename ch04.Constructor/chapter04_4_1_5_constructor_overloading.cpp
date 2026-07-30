#include <iostream>

struct Point
{
    int x, y;
};

class Rectangle
{
public:
    Rectangle()
    {
        position.x = 0;
        position.y = 0;
        width = 1;
        height = 1;
    }

    Rectangle(int width, int height)
    {
        position.x = 0;
        position.y = 0;
        this->width = width;
        this->height = height;
    }

    Rectangle(int x, int y, int width, int height)
    {
        position.x = x;
        position.y = y;
        this->width = width;
        this->height = height;
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
    Rectangle second(100, 50);
    Rectangle third(10, 20, 100, 50);

    first.Print();
    second.Print();
    third.Print();
}
