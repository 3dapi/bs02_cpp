#include <chrono>
#include <ctime>
#include <iostream>

int main()
{
    static_assert(std::chrono::steady_clock::is_steady);

    auto now = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(now);

    std::cout << (time != std::time_t{}) << '\n';
}
