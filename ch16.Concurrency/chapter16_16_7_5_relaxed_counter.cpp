#include <atomic>
#include <iostream>
#include <thread>

int main()
{
    std::atomic<int> requestCount = 0;

    auto countRequest = [&]
    {
        for (int i = 0; i < 1000; ++i)
        {
            requestCount.fetch_add(1, std::memory_order_relaxed);
        }
    };

    std::jthread first{countRequest};
    std::jthread second{countRequest};

    first.join();
    second.join();

    std::cout << requestCount.load(std::memory_order_relaxed) << '\n';
}
