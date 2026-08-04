#include <iostream>
#include <vector>

int main()
{
    std::vector<int> values{10, 20, 30};
    auto iterator = values.begin();

    std::cout << *iterator << '\n';

    ++iterator;
    std::cout << *iterator << '\n';
}
