#include <iostream>
#include <stdexcept>

int Divide(int left, int right)
{
    if (right == 0)
    {
        throw std::invalid_argument(
            "0으로 나눌 수 없습니다."
        );
    }

    return left / right;
}

int main()
{
    try
    {
        int result = Divide(10, 0);

        std::cout << result << '\n';
    }
    catch (const std::invalid_argument& error)
    {
        std::cerr << error.what() << '\n';
    }
}
