#include <iostream>
#include <set>

int main()
{
    std::multiset<int> scores{70, 80, 80, 80, 190, 100};

    auto [first, last] = scores.equal_range(80);

    for (auto itr = first; itr != last; ++itr)
    {
        std::cout << *itr << ' ';
    }
    std::cout << '\n';

    auto position = scores.find(80);

    if (position != scores.end())
    {
        scores.erase(position);
    }

    std::cout << scores.count(80) << '\n';
}
