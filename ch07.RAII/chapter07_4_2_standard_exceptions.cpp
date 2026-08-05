#include <iostream>
#include <stdexcept>

int CheckedValue(int value)
{
    if (value < 0)
    {
        throw std::invalid_argument(
            "값은 0 이상이어야 합니다."
        );
    }

    if (value > 100)
    {
        throw std::out_of_range(
            "값이 허용 범위를 벗어났습니다."
        );
    }

    return value;
}

int main()
{
    try
    {
        std::cout << CheckedValue(150) << '\n';
    }
    catch (const std::exception& error)
    {
        std::cerr << error.what() << '\n';
    }
}
