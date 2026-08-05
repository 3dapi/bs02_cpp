#include <iostream>
#include <thread>

int main()
{
    int firstResult = 0;
    int secondResult = 0;

    std::jthread first{
        [&]
        {
            firstResult = 20;
        }};

    std::jthread second{
        [&]
        {
            secondResult = 22;
        }};

    first.join();
    second.join();

    std::cout << firstResult + secondResult << '\n';
}
