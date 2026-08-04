#include <algorithm>
#include <array>
#include <iostream>

void ProcessData(const int* values, std::size_t size)
{
    if (size > 0)
    {
        std::cout << values[0] << '\n';
    }
}

int main()
{
    std::array<int, 5> values{30, 10, 50, 20, 40};

    std::sort(values.begin(), values.end());
    auto position = std::find(values.begin(), values.end(), 30);

    if (position != values.end())
    {
        std::cout << *position << '\n';
    }

    ProcessData(values.data(), values.size());
}
