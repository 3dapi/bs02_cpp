#include <forward_list>
#include <iostream>
#include <iterator>

int main()
{
    std::forward_list<int> values{10, 20, 30};
    auto count = std::distance(values.begin(), values.end());

    std::cout << count << '\n';
}
