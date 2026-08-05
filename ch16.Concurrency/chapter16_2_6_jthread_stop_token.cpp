#include <atomic>
#include <chrono>
#include <iostream>
#include <stop_token>
#include <thread>

using namespace std::chrono_literals;

void Worker(std::stop_token stopToken, std::atomic<int>& count)
{
    while (!stopToken.stop_requested())
    {
        ++count;
        std::this_thread::sleep_for(1ms);
    }
}

int main()
{
    std::atomic<int> count = 0;
    std::jthread worker{Worker, std::ref(count)};

    std::this_thread::sleep_for(10ms);
    worker.request_stop();
    worker.join();

    std::cout << (count.load() > 0) << '\n';
}
