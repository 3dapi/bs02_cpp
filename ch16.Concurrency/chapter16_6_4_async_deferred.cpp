#include <future>
#include <iostream>
#include <thread>

int main()
{
    const std::thread::id callerId = std::this_thread::get_id();

    auto deferred = std::async(
        std::launch::deferred,
        []
        {
            return std::this_thread::get_id();
        });

    const std::thread::id workerId = deferred.get();

    std::cout << std::boolalpha
              << (callerId == workerId)
              << '\n';
}
