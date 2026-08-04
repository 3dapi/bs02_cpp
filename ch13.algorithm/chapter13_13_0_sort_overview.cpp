#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> values{40, 10, 30, 20};

    std::sort(values.begin(), values.end());

    for (int value : values)
    {
        std::cout << value << ' ';
    }
}
