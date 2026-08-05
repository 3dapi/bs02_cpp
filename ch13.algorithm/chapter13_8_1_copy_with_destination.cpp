#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> source{10, 20, 30};
    std::vector<int> destination(source.size());

    std::copy(
        source.begin(),
        source.end(),
        destination.begin());

    for (int value : destination)
    {
        std::cout << value << ' ';
    }
}
