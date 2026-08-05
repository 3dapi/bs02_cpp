#include <chrono>
#include <iostream>

void RunTask()
{
    volatile int result = 0;

    for (int i = 0; i < 10000; ++i)
    {
        result += i;
    }
}

int main()
{
    using Clock = std::chrono::steady_clock;

    const auto start = Clock::now();
    RunTask();
    const auto end = Clock::now();

    const auto milliseconds =
        std::chrono::duration<double, std::milli>{end - start};

    std::cout << milliseconds.count() << " ms\n";
}
