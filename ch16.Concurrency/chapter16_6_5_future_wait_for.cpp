#include <chrono>
#include <future>
#include <iostream>
#include <thread>

using namespace std::chrono_literals;

int main()
{
    auto result = std::async(
        std::launch::async,
        []
        {
            std::this_thread::sleep_for(5ms);
            return 42;
        });

    if (result.wait_for(100ms) == std::future_status::ready)
    {
        std::cout << result.get() << '\n';
    }
}
