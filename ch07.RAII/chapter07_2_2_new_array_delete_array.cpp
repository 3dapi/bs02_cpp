#include <cstddef>
#include <iostream>

int main()
{
    std::size_t count = 5;
    int* values = new int[count]{};

    for (std::size_t i = 0; i < count; ++i)
    {
        values[i] = static_cast<int>(i * 10);
    }

    for (std::size_t i = 0; i < count; ++i)
    {
        std::cout << values[i] << ' ';
    }

    std::cout << '\n';

    delete[] values;
}
