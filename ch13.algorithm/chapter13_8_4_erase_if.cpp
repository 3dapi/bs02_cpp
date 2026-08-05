#include <iostream>
#include <vector>

int main()
{
    std::vector<int> values{10, -5, 20, -1, 30};

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
}
