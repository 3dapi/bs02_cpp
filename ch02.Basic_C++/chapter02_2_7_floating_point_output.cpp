#include <iomanip>
#include <iostream>

int main()
{
    double value = 1234.56789;
    std::cout << std::fixed << std::setprecision(2) << value << '\n';
    std::cout << std::scientific << std::setprecision(4) << value << '\n';
}
