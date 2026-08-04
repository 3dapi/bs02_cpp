#include <algorithm>
#include <deque>
#include <iostream>

int main()
{
    std::deque<int> values{30, 10, 20};

    std::cout << values[1] << ' '
              << values.at(2) << '\n';

    std::sort(values.begin(), values.end());
    std::cout << values.front() << '\n';
}
