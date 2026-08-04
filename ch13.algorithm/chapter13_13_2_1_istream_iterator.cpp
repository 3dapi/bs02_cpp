#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>

int main()
{
    std::istringstream input("10 20 100 30");
    std::istream_iterator<int> first{input};
    std::istream_iterator<int> last;

    std::istream_iterator<int> found = std::find(first, last, 100);

    if (found != last)
    {
        std::cout << *found << '\n';
    }
}
