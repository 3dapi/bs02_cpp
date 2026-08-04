#include <iostream>
#include <vector>

int main()
{
    std::vector<int> values{1, 2, 3, 4, 5, 6};

    for (auto iterator = values.begin(); iterator != values.end();)
    {
        if (*iterator % 2 == 0)
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
}
