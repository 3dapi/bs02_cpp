#include <cstddef>
#include <iostream>

int main()
{
    char character = 'A';
    signed char s = - 10;
    unsigned char u = 200;
    std::byte data = static_cast<std::byte>(0x7F);
    std::cout << character << ' ' << static_cast<int>(s) << ' ' << static_cast<int>(u) << ' ' << std::to_integer<int>(data) << '\n';
}
