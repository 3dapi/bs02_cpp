#include <iomanip>
#include <iostream>

int main()
{
    std::cout << std::left
              << std::setw(12) << "Name"
              << std::right
              << std::setw(8) << "Score"
              << '\n';

    std::cout << std::left
              << std::setw(12) << "Knight"
              << std::right
              << std::setw(8) << 1500
              << '\n';
}
