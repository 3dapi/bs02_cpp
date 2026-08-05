#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> left{1, 2, 3};
    std::vector<int> right{10, 20, 30};
    std::vector<int> sums(left.size());

    std::transform(
        left.begin(),
        left.end(),
        right.begin(),
        sums.begin(),
        std::plus<>{});

    for (int value : sums)
    {
        std::cout << value << ' ';
    }
}
