#include <iostream>

int GetValue()
{
    return 10;
}

int main()
{
    if (int value = GetValue(); value > 0)
    {
        std::cout << "양수: " << value << '\n';
    }
    else
    {
        std::cout << "0 또는 음수: " << value << '\n';
    }
}
