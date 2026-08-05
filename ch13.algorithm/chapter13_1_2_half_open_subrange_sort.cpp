#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> values{10, 50, 40, 30, 20};

    auto first = values.begin() + 1;
    auto last = values.begin() + 4;

    std::sort(first, last);

    for (int value : values)
    {
        std::cout << value << ' ';
    }
}
