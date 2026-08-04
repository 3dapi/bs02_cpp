#include <cstddef>
#include <iostream>
#include <memory>

int main()
{
    std::unique_ptr<int[]> values =
        std::make_unique<int[]>(10);

    for (std::size_t i = 0; i < 10; ++i)
    {
        values[i] = static_cast<int>(i * 10);
    }

    for (std::size_t i = 0; i < 10; ++i)
    {
        std::cout << values[i] << ' ';
    }

    std::cout << '\n';
}
