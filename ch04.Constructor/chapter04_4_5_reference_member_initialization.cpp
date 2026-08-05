#include <iostream>

struct Point
{
    int x, y;
};

class PointView
{
public:
    PointView(Point& point)
        : point(point)
    {
    }

    void Move(int x, int y)
    {
        point.x = x;
        point.y = y;
    }

private:
    Point& point;
};

int main()
{
    Point position{10, 20};
    PointView view(position);

    view.Move(30, 40);

    std::cout << position.x << ", " << position.y << '\n';
}
