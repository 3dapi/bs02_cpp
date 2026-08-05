#include <chrono>
#include <future>
#include <iostream>
#include <thread>

using namespace std::chrono_literals;

int Work(int value)
{
    std::this_thread::sleep_for(5ms);
    return value;
}

int main()
{
    auto first = std::async(std::launch::async, Work, 10);
    auto second = std::async(std::launch::async, Work, 20);

    std::cout << first.get() + second.get() << '\n';
}
