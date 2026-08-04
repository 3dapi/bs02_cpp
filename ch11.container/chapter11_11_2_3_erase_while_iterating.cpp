#include <iostream>
#include <vector>

int main()
{
    std::vector<int> values{3, -1, 5, -2, 7};

    for (auto iterator = values.begin(); iterator != values.end();)
    {
        if (*iterator < 0)
        {
            iterator = values.erase(iterator);
        }
        else
        {
            ++iterator;
        }
    }

    for (int value : values)
    {
        std::cout << value << ' ';
    }

    std::cout << '\n';
}
