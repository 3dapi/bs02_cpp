#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> values{1, 2, 3, 4};
    std::vector<int> squares(values.size());

    std::transform(
        values.begin(),
        values.end(),
        squares.begin(),
        [](int value)
        {
            return value * value;
        });

    for (int value : squares)
    {
        std::cout << value << ' ';
    }
}
