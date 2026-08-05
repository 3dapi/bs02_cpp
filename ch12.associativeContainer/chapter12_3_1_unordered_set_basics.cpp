#include <iostream>
#include <unordered_set>

int main()
{
    std::unordered_set<int> ids{30, 10, 20, 10};
    std::unordered_multiset<int> scores{80, 90, 80, 70};

    ids.insert(1001);

    if (ids.contains(1001))
    {
        ids.erase(1001);
    }

    std::cout << ids.size() << ' ' << scores.count(80) << '\n';
}
