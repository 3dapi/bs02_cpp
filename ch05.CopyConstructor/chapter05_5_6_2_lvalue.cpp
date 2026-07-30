#include <iostream>

int& Select(int& value)
{
    return value;
}

int main()
{
    int number = 10;
    Select(number) = 100;

    std::cout << number << '\n';
}
