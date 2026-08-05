#include <atomic>
#include <chrono>
#include <iostream>
#include <semaphore>
#include <thread>

using namespace std::chrono_literals;

std::counting_semaphore<2> slots{2};
std::atomic<int> active = 0;
std::atomic<int> maximumActive = 0;

void UseResource()
{
    slots.acquire();

    const int current = ++active;
    int maximum = maximumActive.load();

    while (maximum < current &&
           !maximumActive.compare_exchange_weak(maximum, current))
    {
    }

    std::this_thread::sleep_for(5ms);
    --active;

    slots.release();
}

int main()
{
    std::jthread first{UseResource};
    std::jthread second{UseResource};
    std::jthread third{UseResource};

    first.join();
    second.join();
    third.join();

    std::cout << maximumActive.load() << '\n';
}
