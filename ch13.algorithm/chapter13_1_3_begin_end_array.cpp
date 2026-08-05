#include <algorithm>
#include <iostream>
#include <iterator>

int main()
{
    int values[]{30, 10, 20};
    std::sort(std::begin(values), std::end(values));

    for (int value : values)
    {
        std::cout << value << ' ';
    }
}
