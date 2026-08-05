#include <cstddef>
#include <iostream>
#include <iterator>

int main()
{
    int values[10]{};
    std::size_t count = std::size(values);
    int* first = &values[2];
    int* second = &values[7];
    std::ptrdiff_t distance = second - first;
    std::cout << count << ' ' << distance << '\n';
}
