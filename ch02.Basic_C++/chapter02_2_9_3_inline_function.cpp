#include <iostream>

inline int Square(int value)
{
    return value * value;
}

int main()
{
    std::cout << Square(1 + 2) << '\n';
}
