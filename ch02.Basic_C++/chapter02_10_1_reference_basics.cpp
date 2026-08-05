#include <iostream>

int main()
{
    int value = 10;
    int& reference = value;
    reference = 20;
    int second = 30;
    reference = second;
    std::cout << value << ' ' << second << '\n';
}
