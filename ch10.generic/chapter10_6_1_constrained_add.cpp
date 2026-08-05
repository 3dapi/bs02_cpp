#include <concepts>
#include <iostream>

template <std::integral T>
T AddInteger(T left, T right)
{
    return left + right;
}

int main()
{
    std::cout << AddInteger(10, 20) << '\n';

    // AddInteger(1.5, 2.5); // std::integral을 만족하지 않음
}
