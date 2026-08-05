#include <iostream>

template <typename... Args>
constexpr auto SumFromZero(const Args&... args)
{
    return (0 + ... + args);
}

template <typename... Conditions>
bool All(Conditions... conditions)
{
    return (... && conditions);
}

template <typename... Args>
void PrintFold(const Args&... args)
{
    ((std::cout << args << ' '), ...);
    std::cout << '\n';
}

template <typename... Args>
void PrintCompact(const Args&... args)
{
    (std::cout << ... << args) << '\n';
}

int main()
{
    static_assert(SumFromZero() == 0);
    static_assert(SumFromZero(1, 2, 3) == 6);

    std::cout << std::boolalpha << All(true, true, false) << '\n';
    PrintFold(10, 20, 30);
    PrintCompact("Player hp=", 100);
}
