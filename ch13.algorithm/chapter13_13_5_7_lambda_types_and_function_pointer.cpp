#include <iostream>
#include <type_traits>

int main()
{
    int (*add)(int, int) = [](int left, int right)
    {
        return left + right;
    };

    auto first = [](int value)
    {
        return value * 2;
    };

    auto second = [](int value)
    {
        return value * 2;
    };

    static_assert(!std::is_same_v<decltype(first), decltype(second)>);

    std::cout << add(10, 20) << '\n';
}
