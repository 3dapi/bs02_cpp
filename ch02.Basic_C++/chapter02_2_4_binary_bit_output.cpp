#include <bitset>
#include <iostream>

int main()
{
    unsigned int value = 13;
    std::bitset<8> bits(value);
    std::cout << bits << '\n';
    bits.set(1);
    bits.flip(0);
    std::cout << bits << '\n';
}
