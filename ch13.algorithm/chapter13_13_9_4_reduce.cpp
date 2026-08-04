#include <iostream>
#include <numeric>
#include <vector>

int main()
{
    std::vector<int> values{10, 20, 30, 40};
    int total = std::reduce(values.begin(), values.end(), 0);

    std::cout << total << '\n';
}
