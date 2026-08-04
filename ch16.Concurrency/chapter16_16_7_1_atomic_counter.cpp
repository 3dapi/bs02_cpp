#include <atomic>
#include <iostream>
#include <thread>

std::atomic<int> counter = 0;

void Increase()
{
    for (int i = 0; i < 100'000; ++i)
    {
        ++counter;
    }
}

int main()
{
    std::jthread first{Increase};
    std::jthread second{Increase};

    first.join();
    second.join();

    std::cout << counter.load() << '\n';
}
