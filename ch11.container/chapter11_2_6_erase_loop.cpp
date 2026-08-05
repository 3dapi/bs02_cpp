#include <iostream>
#include <vector>

int main()
{
    std::vector<int> values{1, -1, 2, -2, 3};

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

    std::cout << values.size() << '\n';
}
