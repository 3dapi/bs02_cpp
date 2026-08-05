#include <iostream>
#include <type_traits>

template <typename T>
void InspectForwarding(T&& value)
{
    using ValueType = std::remove_reference_t<T>;

    if constexpr (std::is_lvalue_reference_v<T>)
    {
        std::cout << "lvalue";
    }
    else
    {
        std::cout << "rvalue";
    }

    if constexpr (std::is_const_v<ValueType>)
    {
        std::cout << ", const";
    }

    std::cout << '\n';
    (void)value;
}

int main()
{
    int number = 10;
    const int limit = 20;

    InspectForwarding(number);
    InspectForwarding(limit);
    InspectForwarding(10);
}
