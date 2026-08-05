#include <iostream>

int main()
{
    int&& value = 10;
    value = 20;

    std::cout << value << '\n';
}
