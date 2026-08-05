#include <iostream>
#include <vector>

int main()
{
    std::vector<int> values{10, 20, 30};

    auto first = values.begin();
    auto last = values.end();

    for (auto iterator = first; iterator != last; ++iterator)
    {
        std::cout << *iterator << ' ';
    }
}
