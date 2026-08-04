#include <iostream>
#include <list>

int main()
{
    std::list<int> values{4, -1, 3, 2, -5};

    values.sort();
    values.remove_if(
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
