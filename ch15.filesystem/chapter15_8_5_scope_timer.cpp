#include <chrono>
#include <iostream>
#include <string>
#include <utility>

class ScopeTimer
{
public:
    explicit ScopeTimer(std::string label)
        : label(std::move(label)),
          start(std::chrono::steady_clock::now())
    {
    }

    ~ScopeTimer()
    {
        const auto end = std::chrono::steady_clock::now();
        const auto elapsed =
            std::chrono::duration<double, std::milli>{end - start};

        std::clog << label << ": "
                  << elapsed.count() << " ms\n";
    }

private:
    std::string label;
    std::chrono::steady_clock::time_point start;
};

int main()
{
    ScopeTimer timer{"task"};

    volatile int result = 0;
    for (int i = 0; i < 10000; ++i)
    {
        result += i;
    }
}
