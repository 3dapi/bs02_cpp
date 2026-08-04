#include <chrono>
#include <iostream>

int main()
{
    using Clock = std::chrono::steady_clock;

    Clock::time_point start = Clock::now();
    auto deadline = start + std::chrono::seconds{5};

    std::cout << std::boolalpha
              << (Clock::now() < deadline) << '\n';
}
