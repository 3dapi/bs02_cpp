#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> values{10, 20, 30, 40};
    int value = 25;

    auto position = std::lower_bound(values.begin(), values.end(), value);
    values.insert(position, value);

    for (int element : values)
    {
        std::cout << element << ' ';
    }
}
