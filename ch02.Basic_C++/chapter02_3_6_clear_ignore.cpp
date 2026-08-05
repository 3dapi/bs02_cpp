#include <iostream>
#include <limits>

int main()
{
    int value = 0;
    while (true)
    {
        std::cout << "정수: ";
        if (std::cin >> value)
            break;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cout << value << '\n';
}
