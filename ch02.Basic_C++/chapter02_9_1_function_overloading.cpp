#include <iostream>

int Add(int a, int b)
{
    return a + b;
}

double Add(double a, double b)
{
    return a + b;
}

int Add(int a, int b, int c)
{
    return a + b + c;
}

int main()
{
    std::cout << Add(10, 20) << ' ' << Add(1.5, 2.5) << ' ' << Add(10, 20, 30) << '\n';
}
