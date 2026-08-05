#include <iostream>

int main()
{
    double first = 0.5;
    double second = first;
    std::cout << std::boolalpha << (first == second) << ' ' << (0.1 + 0.2 == 0.3) << '\n';
}
