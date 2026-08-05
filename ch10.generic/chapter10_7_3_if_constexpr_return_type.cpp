#include <iostream>
#include <type_traits>

template <typename T>
auto GetValue(T value)
{
    if constexpr (std::is_pointer_v<T>)
    {
        return *value;
    }
    else
    {
        return value;
    }
}

int main()
{
    int number = 10;

    std::cout << GetValue(number) << '\n';
    std::cout << GetValue(&number) << '\n';
}
