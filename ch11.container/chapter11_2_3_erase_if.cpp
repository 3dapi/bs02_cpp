#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> values{3, -1, 5, -2, 7};

    std::erase_if(
        values,
        [](int value)
        {
            return value < 0;
        });

    for (int value : values)
    {
        std::cout << value << ' ';
    }

    std::cout << '\n';
}
