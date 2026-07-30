#include <iomanip>
#include <iostream>

int main()
{
    auto flags = std::cout.flags();
    auto precision = std::cout.precision();
    char fill = std::cout.fill();
    std::cout << std::hex << std::setprecision(4) << std::setfill('0') << 255 << '\n';
    std::cout.flags(flags);
    std::cout.precision(precision);
    std::cout.fill(fill);
}
