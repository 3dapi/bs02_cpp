#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

int main()
{
    std::mutex mutex;
    std::condition_variable condition;
    bool ready = false;
    int result = 0;

    std::jthread consumer{
        [&]
        {
            std::unique_lock lock{mutex};

            condition.wait(lock, [&]
            {
                return ready;
            });

            result = 42;
        }};

    {
        std::lock_guard lock{mutex};
        ready = true;
    }

    condition.notify_one();
    consumer.join();

    std::cout << result << '\n';
}
