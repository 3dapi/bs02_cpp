#include <iostream>

template <typename T>
T Convert(int value)
{
    return static_cast<T>(value);
}

template <typename Result, typename Left, typename Right>
Result AddAs(const Left& left, const Right& right)
{
    return static_cast<Result>(left + right);
}

template <typename T>
T GetMin(T left, T right)
{
    return right < left ? right : left;
}

int main()
{
    double realValue = Convert<double>(10);
    double result = AddAs<double>(10, 2.5f);
    int truncated = GetMin<int>(3.8, 2.2);

    std::cout << realValue << '\n';
    std::cout << result << '\n';
    std::cout << truncated << '\n';
}
