#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

void PrintValues(const std::vector<int>& values)
{
    for (int value : values)
    {
        std::cout << value << ' ';
    }

    std::cout << '\n';
}

int main()
{
    std::vector<int> first{5, 1, 9, 3};
    std::vector<int> second = first;

    std::sort(first.begin(), first.end(), std::greater<int>{});
    std::sort(
        second.begin(),
        second.end(),
        [](int left, int right)
        {
            return left > right;
        });

    PrintValues(first);
    PrintValues(second);
}
