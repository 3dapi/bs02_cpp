#include <iomanip>
#include <iostream>

int main()
{
    int value = 255;

    std::cout << std::dec << value << '\n';
    std::cout << std::hex << value << '\n';
    std::cout << std::oct << value << '\n';
    std::cout << std::dec << value << '\n';
}
