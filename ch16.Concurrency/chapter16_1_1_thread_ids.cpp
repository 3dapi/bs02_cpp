#include <iostream>
#include <thread>

int main()
{
    const std::thread::id mainId = std::this_thread::get_id();
    std::thread::id workerId;

    std::jthread worker{
        [&]
        {
            workerId = std::this_thread::get_id();
        }};

    worker.join();

    std::cout << std::boolalpha
              << (mainId != workerId)
              << '\n';
}
