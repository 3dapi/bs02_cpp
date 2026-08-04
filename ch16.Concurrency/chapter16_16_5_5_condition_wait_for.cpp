#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>

using namespace std::chrono_literals;

int main()
{
    std::mutex mutex;
    std::condition_variable condition;
    bool ready = false;

    std::unique_lock lock{mutex};

    const bool result = condition.wait_for(lock, 5ms, [&]
    {
        return ready;
    });

    std::cout << std::boolalpha << result << '\n';
}
