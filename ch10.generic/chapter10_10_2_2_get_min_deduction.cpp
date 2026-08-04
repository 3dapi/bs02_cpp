#include <iostream>

template <typename T>
T GetMin(T left, T right)
{
    return right < left ? right : left;
}

template <typename Left, typename Right>
auto GetMinMixed(const Left& left, const Right& right)
{
    return right < left ? right : left;
}

int main()
{
    int first = GetMin(10, 20);
    double second = GetMin(3.5, 1.2);
    double mixed = GetMinMixed(10, 2.5);

    std::cout << first << '\n';
    std::cout << second << '\n';
    std::cout << mixed << '\n';

    // auto invalid = GetMin(10, 2.5); // T를 하나로 추론할 수 없음
}
