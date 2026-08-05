#include <iostream>
#include <set>

int main()
{
    std::set<int> uniqueIds{30, 10, 20, 10};
    std::multiset<int> scores{80, 90, 80, 70};

    for (int id : uniqueIds)
    {
        std::cout << id << ' ';
    }
    std::cout << '\n';

    for (int score : scores)
    {
        std::cout << score << ' ';
    }
    std::cout << '\n';
}
