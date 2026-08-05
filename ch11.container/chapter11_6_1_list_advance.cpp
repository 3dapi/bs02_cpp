#include <iostream>
#include <iterator>
#include <list>

int main()
{
    std::list<int> values{10, 20, 30};

    auto iterator = values.begin();
    std::advance(iterator, 2);

    std::cout << *iterator << '\n';
}
