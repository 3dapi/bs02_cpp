#include <bitset>
#include <iostream>
#include <string>

int main()
{
    std::bitset<8> permissions{0b0010'0101};

    bool firstBit = permissions.test(0);
    permissions.set(1);
    permissions.reset(2);
    permissions.flip(5);
    permissions[0] = false;

    std::size_t enabledCount = permissions.count();
    std::string bits = permissions.to_string();

    std::cout << std::boolalpha << firstBit << '\n';
    std::cout << enabledCount << ' ' << bits << '\n';
    std::cout << permissions.any() << ' '
              << permissions.none() << ' '
              << permissions.all() << '\n';
}
