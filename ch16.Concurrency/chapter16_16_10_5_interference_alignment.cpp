#include <atomic>
#include <cstddef>
#include <iostream>

struct alignas(64) Counter
{
    std::atomic<long long> value = 0;
};

int main()
{
    Counter first;
    Counter second;

    ++first.value;
    ++second.value;

    std::cout << first.value.load() + second.value.load() << ' '
              << alignof(Counter) << '\n';
}
