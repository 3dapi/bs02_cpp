#include <iostream>
#include <numeric>
#include <vector>

int main()
{
    std::vector<int> left{1, 2, 3};
    std::vector<int> right{10, 20, 30};

    int result = std::inner_product(
        left.begin(),
        left.end(),
        right.begin(),
        0);

    std::cout << result << '\n';
}
