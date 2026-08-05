#include <iostream>

template <typename T>
void PrintValue(const T& value)
{
    std::cout << value << '\n';
}

template <>
void PrintValue<bool>(const bool& value)
{
    std::cout << (value ? "true" : "false") << '\n';
}

int main()
{
    PrintValue(100);
    PrintValue(true);
}
