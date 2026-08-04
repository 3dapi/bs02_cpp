#include <iostream>

void Show(long value)
{
    std::cout << "long: " << value << '\n';
}

template <typename T>
void Show(T value)
{
    std::cout << "template: " << value << '\n';
}

void Print(int value)
{
    std::cout << "int: " << value << '\n';
}

template <typename T>
void Print(const T& value)
{
    std::cout << "template: " << value << '\n';
}

int main()
{
    Show(10);
    Print<>(10);
    Print<int>(10);
}
