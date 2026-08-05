#include <iostream>
#include <string>
#include <type_traits>

template <typename T>
std::enable_if_t<std::is_integral_v<T>, T>
DoubleValue(T value)
{
    return value * 2;
}

template <typename T,
          std::enable_if_t<std::is_floating_point_v<T>, int> = 0>
void Describe(T value)
{
    std::cout << "real: " << value << '\n';
}

template <typename T>
auto GetSize(const T& value) -> decltype(value.size())
{
    return value.size();
}

int main()
{
    std::string text = "Knight";

    std::cout << DoubleValue(10) << '\n';
    Describe(3.5);
    std::cout << GetSize(text) << '\n';
}
