#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> values{7, 2, 9, 1, 5, 4};
    auto middle = values.begin() + values.size() / 2;

    std::nth_element(values.begin(), middle, values.end());

    std::cout << *middle << '\n';
}
