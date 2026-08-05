#include <iostream>
#include <list>

int main()
{
    std::list<int> values{1, 2, 3, 4};

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
