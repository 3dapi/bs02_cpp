#include <iostream>

int GetReadValue()
{
    static int value = 10;
    return value--;
}

int GetCommand()
{
    return 1;
}

int main()
{
    while(int value = GetReadValue())
    {
        std::cout << value << '\n';
    }

    int value = GetReadValue();
    while(value > 0)
    {
        std::cout << value << '\n';
        value = GetReadValue();
    }
}