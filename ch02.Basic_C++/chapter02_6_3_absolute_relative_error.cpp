#include <algorithm>
#include <cmath>
#include <iostream>

bool NearlyEqual(double first, double second
                 , double absoluteTolerance, double relativeTolerance)
{
    if (first == second)
        return true;
    if (!std::isfinite(first) || !std::isfinite(second))
        return false;

    double difference = std::abs(first - second);
    if (difference <= absoluteTolerance)
        return true;
    double scale = std::max(std::abs(first), std::abs(second));
    return difference <= scale * relativeTolerance;
}

int main()
{
    std::cout << std::boolalpha << NearlyEqual(0.1 + 0.2, 0.3, 1e-12, 1e-12) << '\n';
}
