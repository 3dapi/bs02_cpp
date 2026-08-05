#include <iostream>
#include <vector>

int main()
{
    std::vector<int> values{10, 20, 30};
    values.reserve(10);

    auto first = values.begin();
    const std::size_t oldSize = values.size();

    values.push_back(40);

    std::cout << *first << '\n';
    std::cout << values[oldSize] << '\n';
}
