#include <iostream>

int main()
{
    int value = 255;
    std::cout << std::dec << value << '\n' << std::showbase << std::hex << value << '\n' << std::oct << value << '\n';
}
