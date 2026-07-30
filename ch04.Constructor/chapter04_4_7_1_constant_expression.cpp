#include <iostream>

int main()
{
    constexpr int width = 100;
    constexpr int height = 50;
    constexpr int area = width * height;

    static_assert(area == 5000);
    std::cout << area << '\n';
}
