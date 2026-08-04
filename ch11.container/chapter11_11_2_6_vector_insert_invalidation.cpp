#include <iostream>
#include <vector>

int main()
{
    std::vector<int> values{10, 20, 30, 40};
    values.reserve(10);

    auto first = values.begin();
    const int firstValue = *first;

    values.insert(values.begin() + 1, 15);

    std::cout << firstValue << ' ' << *first << '\n';
    std::cout << values[3] << '\n';
}
