#include <iostream>

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
    Print(10);
    Print(3.5);
}
