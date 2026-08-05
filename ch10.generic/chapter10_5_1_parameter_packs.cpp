#include <cstddef>
#include <iostream>

template <typename... Types>
class TypeList
{
};

template <typename... Args>
void CountArguments(const Args&... args)
{
    std::cout << sizeof...(Args) << '\n';
    std::cout << sizeof...(args) << '\n';
}

template <int... Values>
struct IntegerSequence
{
    static constexpr std::size_t Size = sizeof...(Values);
};

int main()
{
    TypeList<> emptyTypes;
    TypeList<int, double, const char*> threeTypes;

    CountArguments();
    CountArguments(10, 3.5, "Knight");

    static_assert(IntegerSequence<1, 2, 3, 4>::Size == 4);

    (void)emptyTypes;
    (void)threeTypes;
}
