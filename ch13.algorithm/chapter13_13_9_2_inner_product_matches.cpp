#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

int main()
{
    std::vector<int> left{1, 2, 3};
    std::vector<int> right{1, 9, 3};

    int matches = std::inner_product(
        left.begin(),
        left.end(),
        right.begin(),
        0,
        std::plus<>{},
        std::equal_to<>{});

    std::cout << matches << '\n';
}
