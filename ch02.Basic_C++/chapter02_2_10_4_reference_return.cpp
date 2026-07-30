#include <iostream>

int& GetElement(int* values, int index)
{
    return values[index];
}

const int& GetElement(const int* values, int index)
{
    return values[index];
}

int main()
{
    int values[]{ 10, 20, 30 };
    GetElement(values, 1) = 100;
    const int constValues[]{ 1, 2, 3 };
    std::cout << values[1] << ' ' << GetElement(constValues, 2) << '\n';
}
