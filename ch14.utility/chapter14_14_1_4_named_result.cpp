#include <iostream>

struct DivisionResult
{
    int quotient;
    int remainder;
};

DivisionResult Divide(int value, int divisor)
{
    return {value / divisor, value % divisor};
}

int main()
{
    DivisionResult result = Divide(17, 5);
    std::cout << result.quotient << ' ' << result.remainder << '\n';
}
