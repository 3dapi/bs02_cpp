#include <iostream>

int main()
{
    char character = '\0';
    std::cin >> std::noskipws;
    while (std::cin >> character)
    {
        std::cout << character;
    }
}
