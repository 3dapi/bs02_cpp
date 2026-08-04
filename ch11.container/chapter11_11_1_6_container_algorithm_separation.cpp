#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> dynamicValues{4, 1, 3, 2};
    std::array<int, 4> fixedValues{8, 5, 7, 6};

    std::sort(dynamicValues.begin(), dynamicValues.end());
    std::sort(fixedValues.begin(), fixedValues.end());

    std::cout << dynamicValues.front() << ' '
              << fixedValues.front() << '\n';
}
