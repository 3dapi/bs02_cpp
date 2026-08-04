#include <atomic>
#include <iostream>
#include <latch>
#include <thread>

int main()
{
    std::latch ready{3};
    std::atomic<int> started = 0;

    auto worker = [&]
    {
        ready.count_down();
        ready.wait();
        ++started;
    };

    std::jthread first{worker};
    std::jthread second{worker};
    std::jthread third{worker};

    first.join();
    second.join();
    third.join();

    std::cout << started.load() << '\n';
}
