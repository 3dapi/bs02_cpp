#include <execution>
#include <iostream>
#include <numeric>
#include <vector>

int main()
{
    std::vector<int> values{1, 2, 3, 4, 5};

    const int total = std::reduce(
        std::execution::par,
        values.begin(),
        values.end(),
        0);

    std::cout << total << '\n';
}
