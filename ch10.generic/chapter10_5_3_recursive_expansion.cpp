#include <iostream>

void PrintRecursive()
{
    std::cout << '\n';
}

template <typename First, typename... Rest>
void PrintRecursive(const First& first, const Rest&... rest)
{
    std::cout << first;

    if constexpr (sizeof...(Rest) > 0)
    {
        std::cout << ' ';
    }

    PrintRecursive(rest...);
}

int main()
{
    PrintRecursive(10, 3.5, "Knight");
}
