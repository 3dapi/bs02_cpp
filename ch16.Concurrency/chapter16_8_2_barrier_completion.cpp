#include <atomic>
#include <barrier>
#include <iostream>
#include <thread>

int main()
{
    std::atomic<int> phaseCount = 0;

    std::barrier syncPoint{
        2,
        [&]() noexcept
        {
            ++phaseCount;
        }};

    auto worker = [&]
    {
        for (int phase = 0; phase < 3; ++phase)
        {
            syncPoint.arrive_and_wait();
        }
    };

    std::jthread first{worker};
    std::jthread second{worker};

    first.join();
    second.join();

    std::cout << phaseCount.load() << '\n';
}
