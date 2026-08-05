#include <iostream>
#include <mutex>
#include <thread>

int counter = 0;
std::mutex counterMutex;

void Increase()
{
    for (int i = 0; i < 100'000; ++i)
    {
        std::lock_guard lock{counterMutex};
        ++counter;
    }
}

int main()
{
    std::jthread first{Increase};
    std::jthread second{Increase};

    first.join();
    second.join();

    std::cout << counter << '\n';
}
