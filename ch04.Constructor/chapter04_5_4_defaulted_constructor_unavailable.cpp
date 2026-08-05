#include <iostream>

class Point
{
public:
    Point(int x, int y)
        : x(x), y(y)
    {
    }

    int X() const
    {
        return x;
    }

private:
    int x;
    int y;
};

class Rectangle
{
public:
    Rectangle() = default;

    Rectangle(Point position, int width, int height)
        : position(position), width(width), height(height)
    {
    }

    int X() const
    {
        return position.X();
    }

private:
    Point position;
    int width = 1;
    int height = 1;
};

int main()
{
    // Rectangle first;   // 오류: Rectangle()은 삭제된 함수
    Rectangle second(Point(10, 20), 100, 50);

    std::cout << second.X() << '\n';
}
