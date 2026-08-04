#include <iostream>
#include <type_traits>

template <typename T>
void Describe(const T& value)
{
    if constexpr (std::is_pointer_v<T>)
    {
        if (value != nullptr)
        {
            std::cout << "pointer value: " << *value << '\n';
        }
    }
    else
    {
        std::cout << "value: " << value << '\n';
    }
}

int main()
{
    int number = 10;

    Describe(number);
    Describe(&number);
}
