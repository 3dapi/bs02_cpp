#include <iostream>
#if 0
#endif

int main()
{
    int count{ 10 };
    double speed{ 3.5 };
    constexpr int value = 100;
    char code{ value };
    std::cout << count << ' ' << speed << ' ' << code << '\n';
    // int error{ 3.5 }; // 오류
    // 오류: 축소 변환
}
