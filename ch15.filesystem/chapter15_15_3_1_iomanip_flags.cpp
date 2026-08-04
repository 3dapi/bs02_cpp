#include <iomanip>
#include <iostream>

int main()
{
    std::cout << std::setfill('0')
              << std::setw(5)
              << 42
              << '\n';

    std::cout << std::showbase << std::hex << 255 << '\n';
    std::cout << std::dec << std::boolalpha << true << '\n';
}
