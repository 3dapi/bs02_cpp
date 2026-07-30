#include <iostream>

int main()
{
    constexpr int width = 100;
    constexpr int height = 50;

    // width = 200;   // 오류

    std::cout << width * height << '\n';
}
