#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main()
{
    std::vector<int> values{10, 20, 30};
    std::ostream_iterator<int> output{std::cout, " "};

    std::copy(values.begin(), values.end(), output);
}
