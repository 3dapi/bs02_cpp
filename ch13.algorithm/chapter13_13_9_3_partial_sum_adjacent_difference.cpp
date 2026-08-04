#include <iostream>
#include <numeric>
#include <vector>

int main()
{
    std::vector<int> values{10, 20, 30, 40};
    std::vector<int> sums(values.size());
    std::vector<int> restored(values.size());

    std::partial_sum(
        values.begin(),
        values.end(),
        sums.begin());

    std::adjacent_difference(
        sums.begin(),
        sums.end(),
        restored.begin());

    for (int value : sums)
    {
        std::cout << value << ' ';
    }

    std::cout << '\n';

    for (int value : restored)
    {
        std::cout << value << ' ';
    }
}
