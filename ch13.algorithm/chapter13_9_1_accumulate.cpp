#include <iostream>
#include <numeric>
#include <vector>

int main()
{
    std::vector<double> values{1.5, 2.5, 3.5};

    double correct = std::accumulate(values.begin(), values.end(), 0.0);
    int truncated = std::accumulate(values.begin(), values.end(), 0);

    std::cout << correct << '\n';
    std::cout << truncated << '\n';
}
