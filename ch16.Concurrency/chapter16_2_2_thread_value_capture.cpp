#include <iostream>
#include <thread>

std::thread StartThread()
{
    int localValue = 10;

    return std::thread{
        [localValue]
        {
            std::cout << localValue << '\n';
        }};
}

int main()
{
    std::thread worker = StartThread();
    worker.join();
}
