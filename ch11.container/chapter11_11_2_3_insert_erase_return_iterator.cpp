#include <iostream>
#include <vector>

int main()
{
    std::vector<int> values;

    values.push_back(10);
    values.push_back(20);
    auto inserted = values.insert(values.begin() + 1, 15);
    auto next = values.erase(values.begin());

    std::cout << *inserted << ' ' << *next << '\n';

    values.pop_back();
    std::cout << values.size() << '\n';
}
