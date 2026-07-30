#include <iostream>

int GetReadValue()
{
    static int value = 3;
    return value--;
}

int main()
{
    while (int value = GetReadValue())
    {
        std::cout << value << '\n';
    }
}
