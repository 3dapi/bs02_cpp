#include <atomic>
#include <barrier>
#include <iostream>
#include <thread>

int main()
{
    std::barrier syncPoint{2};
    std::atomic<int> completed = 0;

    auto worker = [&]
    {
        for (int phase = 0; phase < 3; ++phase)
        {
            ++completed;
            syncPoint.arrive_and_wait();
        }
    };

    std::jthread first{worker};
    std::jthread second{worker};

    first.join();
    second.join();

    std::cout << completed.load() << '\n';
}
