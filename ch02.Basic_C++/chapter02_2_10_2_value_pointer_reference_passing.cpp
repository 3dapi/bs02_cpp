#include <iostream>

void IncreaseValue(int value)
{
    ++value;
}

void IncreasePointer(int* value)
{
    if (value)
        ++(*value);
}

void IncreaseReference(int& value)
{
    ++value;
}

int main()
{
    int first = 10, second = 10, third = 10;
    IncreaseValue(first);
    IncreasePointer(&second);
    IncreaseReference(third);
    std::cout << first << ' ' << second << ' ' << third << '\n';
}
