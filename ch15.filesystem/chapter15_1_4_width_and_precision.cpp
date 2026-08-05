#include <iomanip>
#include <iostream>

int main()
{
    double value = 123.456789;

    std::cout << std::setw(8) << 10
              << std::setw(8) << 20 << '\n';

    std::cout << std::setprecision(4) << value << '\n';
    std::cout << std::fixed
              << std::setprecision(4)
              << value << '\n';
}
