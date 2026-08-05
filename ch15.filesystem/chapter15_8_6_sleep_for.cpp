#include <chrono>
#include <iostream>
#include <thread>

int main()
{
    const auto start = std::chrono::steady_clock::now();
    std::this_thread::sleep_for(std::chrono::milliseconds{1});
    const auto end = std::chrono::steady_clock::now();

    std::cout << std::boolalpha
              << (end >= start) << '\n';
}
