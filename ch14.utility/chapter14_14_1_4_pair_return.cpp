#include <iostream>
#include <utility>

std::pair<int, int> DivideWithRemainder(int value, int divisor)
{
    return {value / divisor, value % divisor};
}

int main()
{
    auto [quotient, remainder] = DivideWithRemainder(17, 5);
    std::cout << quotient << ' ' << remainder << '\n';
}
