#include <iostream>

int main()
{
    char character = '\0';
    while (std::cin.get(character))
    {
        std::cout << character;
    }
}
