#include <iomanip>
#include <iostream>

int main()
{
    double result = 0.1 + 0.2;
    std::cout << std::setprecision(17) << result << '\n';
}
