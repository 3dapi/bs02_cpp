#include <cstddef>
#include <iostream>
#include <type_traits>

template <typename T>
void InspectArrayValue(T value)
{
    static_assert(std::is_same_v<T, int*>);
    value[0] = 10;
}

template <typename T, std::size_t Size>
constexpr std::size_t ArraySize(const T (&)[Size]) noexcept
{
    return Size;
}

int main()
{
    int values[5]{};

    InspectArrayValue(values);
    static_assert(ArraySize(values) == 5);

    std::cout << values[0] << '\n';
    std::cout << ArraySize(values) << '\n';
}
