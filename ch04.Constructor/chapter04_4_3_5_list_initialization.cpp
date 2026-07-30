#include <iostream>

struct Point
{
    int x, y;
};

int main()
{
    int value{10};
    Point point{10, 20};

    // int invalid{3.14};   // 오류: 축소 변환

    std::cout << value << '\n';
    std::cout << point.x << ", " << point.y << '\n';
}
