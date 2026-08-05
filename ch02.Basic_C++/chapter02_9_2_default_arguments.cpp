#include <iostream>

void PrintMessage(const char* message, int count = 1)
{
    for (int i = 0; i < count; ++i)
        std::cout << message << '\n';
}

int main()
{
    PrintMessage("Hello");
    PrintMessage("Hello", 3);
}
