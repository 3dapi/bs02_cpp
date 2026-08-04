#include <future>
#include <iostream>
#include <vector>

long long SumRange(
    const std::vector<int>& values,
    std::size_t first,
    std::size_t last)
{
    long long total = 0;

    for (std::size_t index = first; index < last; ++index)
    {
        total += values[index];
    }

    return total;
}

int main()
{
    const std::vector<int> values{1, 2, 3, 4, 5, 6};
    const std::size_t middle = values.size() / 2;

    auto first = std::async(
        std::launch::async,
        SumRange,
        std::cref(values),
        0,
        middle);

    auto second = std::async(
        std::launch::async,
        SumRange,
        std::cref(values),
        middle,
        values.size());

    std::cout << first.get() + second.get() << '\n';
}
