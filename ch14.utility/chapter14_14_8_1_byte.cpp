#include <cstddef>
#include <iostream>

int main()
{
    std::byte flags{0b0000'0101};
    flags |= std::byte{0b0000'1000};
    flags &= std::byte{0b0000'1111};

    unsigned int number = std::to_integer<unsigned int>(flags);
    std::cout << number << '\n';
}
