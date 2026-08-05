#include <iostream>
#include <stdexcept>
#include <thread>

void Worker()
{
    try
    {
        throw std::runtime_error{"worker failed"};
    }
    catch (const std::exception& exception)
    {
        std::cout << exception.what() << '\n';
    }
}

int main()
{
    std::jthread worker{Worker};
}
