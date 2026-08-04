#include <iostream>

int GetMax(int left, int right)
{
    return left < right ? right : left;
}

double GetMax(double left, double right)
{
    return left < right ? right : left;
}

int main()
{
    std::cout << GetMax(10, 20) << '\n';
    std::cout << GetMax(3.5, 7.2) << '\n';
}
