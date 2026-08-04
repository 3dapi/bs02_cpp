#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>

int main()
{
    std::istringstream input("1 2 3 4");

    std::transform(
        std::istream_iterator<int>{input},
        std::istream_iterator<int>{},
        std::ostream_iterator<int>{std::cout, " "},
        [](int value)
        {
            return value * value;
        });
}
