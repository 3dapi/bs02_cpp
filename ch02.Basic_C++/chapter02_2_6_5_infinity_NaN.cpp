#include <cmath>
#include <iostream>
#include <limits>

int main()
{
    double infinity = std::numeric_limits<double>::infinity();
    double nan = std::numeric_limits<double>::quiet_NaN();
    std::cout << std::boolalpha << std::isinf(infinity) << ' ' << std::isnan(nan) << '\n';
}
