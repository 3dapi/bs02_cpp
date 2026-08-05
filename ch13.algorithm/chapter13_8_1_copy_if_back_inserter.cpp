#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main()
{
    std::vector<int> source{10, 15, 20, 25, 30};
    std::vector<int> evenValues;

    std::copy_if(
        source.begin(),
        source.end(),
        std::back_inserter(evenValues),
        [](int value)
        {
            return value % 2 == 0;
        });

    for (int value : evenValues)
    {
        std::cout << value << ' ';
    }
}
