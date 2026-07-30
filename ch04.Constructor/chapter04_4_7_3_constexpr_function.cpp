#include <iostream>

constexpr int CalculateArea(int width, int height)
{
    return width * height;
}

int main()
{
    constexpr int compileTimeArea = CalculateArea(100, 50);

    int width = 200;
    int height = 100;
    int runtimeArea = CalculateArea(width, height);

    static_assert(compileTimeArea == 5000);

    std::cout << compileTimeArea << '\n';
    std::cout << runtimeArea << '\n';
}
