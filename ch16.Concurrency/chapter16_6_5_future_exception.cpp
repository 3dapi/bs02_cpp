#include <future>
#include <iostream>
#include <stdexcept>

int main()
{
    auto result = std::async(
        std::launch::async,
        []() -> int
        {
            throw std::runtime_error{"calculation failed"};
        });

    try
    {
        std::cout << result.get() << '\n';
    }
    catch (const std::exception& exception)
    {
        std::cout << exception.what() << '\n';
    }
}
