#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> values{1, 2, 3, 4, 5, 0, 0};

    std::copy_backward(
        values.begin(),
        values.begin() + 5,
        values.end());

    for (int value : values)
    {
        std::cout << value << ' ';
    }
}
