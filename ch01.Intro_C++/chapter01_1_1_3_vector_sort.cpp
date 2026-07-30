#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> values = { 30, 10, 50, 20, 40 };
    std::sort(values.begin(), values.end());

    for (int value : values)
    {
        std::cout << value << ' ';
    }
}
