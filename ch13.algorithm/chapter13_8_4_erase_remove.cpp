#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> values{10, 20, 30, 20, 40};

    values.erase(
        std::remove(values.begin(), values.end(), 20),
        values.end());

    for (int value : values)
    {
        std::cout << value << ' ';
    }
}
