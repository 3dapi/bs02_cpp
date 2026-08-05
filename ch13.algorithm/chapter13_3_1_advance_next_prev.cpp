#include <iostream>
#include <iterator>
#include <list>

int main()
{
    std::list<int> values{10, 20, 30, 40};

    auto iterator = values.begin();
    std::advance(iterator, 2);
    std::cout << *iterator << '\n';

    auto first = values.begin();
    auto third = std::next(first, 2);
    auto finalElement = std::prev(values.end());

    std::cout << *first << ' ' << *third << ' ' << *finalElement << '\n';
}
