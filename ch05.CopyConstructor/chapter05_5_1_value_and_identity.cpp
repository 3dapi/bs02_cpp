#include <iostream>

int main()
{
    int first = 10;
    int second = 10;

    std::cout << std::boolalpha;
    std::cout << (first == second) << '\n';
    std::cout << (&first == &second) << '\n';
}
