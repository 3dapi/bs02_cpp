#include <iostream>

template <typename T>
T Multiply(T left, T right)
{
    return left * right;
}

int main()
{
    int integerResult = Multiply(3, 4);
    double realResult = Multiply(1.5, 2.0);

    std::cout << integerResult << '\n';
    std::cout << realResult << '\n';
}
