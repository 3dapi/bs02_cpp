#include <atomic>
#include <iostream>
#include <thread>

void UpdateMaximum(std::atomic<int>& maximum, int value)
{
    int current = maximum.load();

    while (current < value &&
           !maximum.compare_exchange_weak(current, value))
    {
    }
}

int main()
{
    std::atomic<int> maximum = 0;

    std::jthread first{UpdateMaximum, std::ref(maximum), 30};
    std::jthread second{UpdateMaximum, std::ref(maximum), 50};

    first.join();
    second.join();

    std::cout << maximum.load() << '\n';
}
