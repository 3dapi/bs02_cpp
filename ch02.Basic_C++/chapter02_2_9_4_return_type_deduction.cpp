#include <iostream>

auto Add(int left, int right)
{
    return left + right;
}

auto Multiply(double left, double right)->double{ return left * right; }int main()
{
    std::cout << Add(10, 20) << ' ' << Multiply(2.0, 3.5) << '\n';
}
