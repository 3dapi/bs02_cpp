#include <algorithm>
#include <chrono>
#include <execution>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> first(10'000, 1);
    std::vector<int> second(first.size());

    const auto start = std::chrono::steady_clock::now();

    std::transform(
        std::execution::par,
        first.begin(),
        first.end(),
        second.begin(),
        [](int value)
        {
            return value * 2;
        });

    const auto end = std::chrono::steady_clock::now();
    const auto elapsed =
        std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << (elapsed.count() >= 0) << ' '
              << second.front() << '\n';
}
