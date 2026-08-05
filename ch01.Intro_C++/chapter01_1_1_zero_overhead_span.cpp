#include <iostream>
#include <span>

int SumLowLevel(const int* values, int count)
{
    int result = 0;
    for (int i = 0; i < count; ++i)
    {
        result += values[i];
    }
    return result;
}

int Sum(std::span<const int> values)
{
    int result{};
    for (int value : values)
    {
        result += value;
    }
    return result;
}

int main()
{
    int values[]{ 10, 20, 30, 40 };
    int lowLevelResult{ SumLowLevel(values, 4) };
    int spanResult{ Sum(values) };

    std::cout << "포인터와 원소 수: " << lowLevelResult << '\n';
    std::cout << "std::span: " << spanResult << '\n';
}
