#include <forward_list>
#include <iostream>

int main()
{
    std::forward_list<int> values{10, 20, 30};

    auto first = values.begin();
    auto copy = first;

    ++first;
    std::cout << *first << '\n';
    std::cout << *copy << '\n';
}
