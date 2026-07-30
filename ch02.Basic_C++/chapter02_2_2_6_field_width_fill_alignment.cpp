#include <iomanip>
#include <iostream>

int main()
{
    std::cout << std::setfill('0') << std::setw(5) << 42 << '\n';
    std::cout << std::setfill(' ') << std::left << std::setw(10) << "Sword" << 1200 << '\n';
}
