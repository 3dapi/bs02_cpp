#include <iostream>

using Callback = void (*)(int);

void PrintValue(int value)
{
    std::cout << value << '\n';
}

int main()
{
    Callback callback = PrintValue;
    callback(10);
}
