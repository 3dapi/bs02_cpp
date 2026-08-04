#include <concepts>
#include <iostream>

template <std::integral T>
void Save(T value)
{
    std::cout << "integer:" << value << '\n';
}

template <std::floating_point T>
void Save(T value)
{
    std::cout << "real:" << value << '\n';
}

int main()
{
    Save(10);
    Save(3.5);
}
