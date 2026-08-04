#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>

int main()
{
    std::vector<int> source{10, 20, 30};

    std::vector<int> destination;
    std::copy(source.begin(), source.end(), std::back_inserter(destination));

    std::deque<int> frontValues;
    std::copy(source.begin(), source.end(), std::front_inserter(frontValues));

    std::set<int> uniqueValues;
    std::copy(
        source.begin(),
        source.end(),
        std::inserter(uniqueValues, uniqueValues.end()));

    for (int value : destination)
    {
        std::cout << value << ' ';
    }

    std::cout << '\n';

    for (int value : frontValues)
    {
        std::cout << value << ' ';
    }
}
