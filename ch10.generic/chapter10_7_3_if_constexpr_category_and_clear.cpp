#include <iostream>
#include <string>
#include <type_traits>
#include <vector>

template <typename T>
void PrintCategory(const T& value)
{
    if constexpr (std::is_integral_v<T>)
    {
        std::cout << "integer: " << value << '\n';
    }
    else if constexpr (std::is_floating_point_v<T>)
    {
        std::cout << "real: " << value << '\n';
    }
    else
    {
        std::cout << "object: " << value << '\n';
    }
}

template <typename T>
void Clear(T& value)
{
    if constexpr (requires { value.clear(); })
    {
        value.clear();
    }
    else
    {
        value = T{};
    }
}

int main()
{
    PrintCategory(10);
    PrintCategory(3.5);
    PrintCategory(std::string("Knight"));

    std::vector<int> values{1, 2, 3};
    int number = 10;

    Clear(values);
    Clear(number);

    std::cout << values.size() << '\n';
    std::cout << number << '\n';
}
