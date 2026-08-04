#include <initializer_list>
#include <iostream>

template <typename T>
void PrintOne(const T& value)
{
    std::cout << value << '\n';
}

template <typename... Args>
void PrintLines(const Args&... args)
{
    (void)std::initializer_list<int>
    {
        (PrintOne(args), 0)...
    };
}

int main()
{
    PrintLines(10, 3.5, "Knight");
}
