#include <iostream>

template <typename... Args>
auto Sum(const Args&... args)
{
    return (... + args);
}

template <typename... Args>
auto SubtractLeft(const Args&... args)
{
    return (... - args);
}

template <typename... Args>
auto SubtractRight(const Args&... args)
{
    return (args - ...);
}

int main()
{
    std::cout << Sum(10, 20, 30) << '\n';
    std::cout << Sum(10, 2.5, 3.5f) << '\n';
    std::cout << SubtractLeft(100, 20, 5) << '\n';
    std::cout << SubtractRight(100, 20, 5) << '\n';
}
